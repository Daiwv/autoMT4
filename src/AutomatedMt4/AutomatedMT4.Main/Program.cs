using System;
using System.Collections.Generic;
using System.Linq;
using AutomatedMt4.DataAccess;
using AutomatedMt4.DataAccess.Entities;
using AutomatedMT4.Scheduler;
using log4net;
using Quartz;

namespace AutomatedMT4.Main
{
    public class Program
    {
        private static  readonly ILog _log = LogManager.GetLogger(typeof(Program));

        static void Main(string[] args)
        {
            log4net.Config.XmlConfigurator.Configure();
            _log.DebugFormat("Program was started");
            var server = new QuartzServer();
            server.Initialize();
            var implementedJobs = new JobProvider().GetImplementedJobsTypes();
            SetScheduledJobs(server, implementedJobs);
        }

        private static void SetScheduledJobs(QuartzServer server, IList<Type> implementedJobs)
        {
            var jobConfigDetailsRepository = new Repository<JobConfigurationDetails>();
            foreach (var implementedJob in implementedJobs)
            {
                var jobConfiguration = jobConfigDetailsRepository.GetAll().FirstOrDefault(x => x.Name == implementedJob.Name);
                if (jobConfiguration != null)
                {
                    IJobDetail job = JobBuilder.Create(implementedJob).WithIdentity(implementedJob.Name, "group1").Build();
                    ITrigger trigger = TriggerBuilder.Create()
                        .WithIdentity(implementedJob.Name + "trigger", "group1")
                        .StartNow()
                        .WithSimpleSchedule(x => x
                                                     .WithIntervalInSeconds((int)jobConfiguration.TriggerTimeInSec)
                                                     .RepeatForever())
                        .Build();

                    server.Scheduler.ScheduleJob(job, trigger);
                }
                else
                {
                    _log.DebugFormat("Job was not configured in db. JobName={0}", implementedJob.Name);
                }
            }
        }
    }
}
