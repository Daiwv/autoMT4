using log4net;
using Quartz;
using Quartz.Impl;

namespace AutomatedMT4.Scheduler
{
    public class QuartzServer : IQuartzServer
    {
        private readonly ILog _logger = LogManager.GetLogger(typeof(QuartzServer));
        private ISchedulerFactory _schedulerFactory;
        private IScheduler _scheduler;

        public void Initialize()
        {
            _logger.DebugFormat("Start to Initialize instance of Quartz server");
            _schedulerFactory = new StdSchedulerFactory();
            _scheduler = _schedulerFactory.GetScheduler();
            _scheduler.Start();
        }

        public void Stop()
        {
           _scheduler.Shutdown(true);
           _logger.DebugFormat("Shutdown Quartz server");
        }
    }
}
