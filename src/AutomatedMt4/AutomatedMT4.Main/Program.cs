using AutomatedMT4.Scheduler;
using AutomatedMT4.Scheduler.Jobs;
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
            var scheduler = server.Scheduler;
        }
    }
}
