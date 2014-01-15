using log4net;
using Quartz;

namespace AutomatedMT4.Scheduler.Jobs
{
    public class DummyJob : IJob
    {
        private readonly ILog _logger = LogManager.GetLogger(typeof(QuartzServer));

        public void Execute(IJobExecutionContext context)
        {
            _logger.DebugFormat("Executing Dummy Job");
        }
    }
}
