using Autofac;
using AutomatedMt4.DataAccess;
using AutomatedMT4.Scheduler;

namespace AutomatedMt4.DI
{
	public class DIContainerBuilder
	{
		private readonly ContainerBuilder _containerBuilder = new ContainerBuilder();

		public IContainer Build()
		{
			_containerBuilder.RegisterGeneric(typeof(Repository<>)).As(typeof(IRepository<>)).InstancePerDependency();
		    _containerBuilder.RegisterType<QuartzServer>().As<IQuartzServer>();
		    _containerBuilder.RegisterType<JobProvider>().AutoActivate();
			return _containerBuilder.Build();
		}
	}
}
