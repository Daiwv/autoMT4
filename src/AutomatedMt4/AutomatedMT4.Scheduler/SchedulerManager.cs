using log4net;
using Quartz;
using Quartz.Impl;

namespace AutomatedMT4.Scheduler
{
    public class SchedulerManager
    {
        private static readonly ILog _log = LogManager.GetLogger(typeof(SchedulerManager));
        private IScheduler _scheduler;
        
        public void Start()
        {
            ISchedulerFactory schedulerFactory = new StdSchedulerFactory();
            _scheduler = schedulerFactory.GetScheduler();
            _scheduler.Start();
            _log.DebugFormat("Start Scheduler");

        }
    }
}
