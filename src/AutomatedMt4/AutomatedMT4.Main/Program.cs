using AutomatedMT4.Scheduler;
using log4net;

namespace AutomatedMT4.Main
{
    public class Program
    {
        private static  readonly ILog _log = LogManager.GetLogger(typeof(Program));

        static void Main(string[] args)
        {
            log4net.Config.XmlConfigurator.Configure();
            _log.DebugFormat("Program was started");
            new QuartzServer().Initialize();
        }
    }
}
