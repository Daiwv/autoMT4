using Autofac;
using AutomatedMt4.DataAccess;

namespace AutomatedMt4.DI
{
	public class DIContainerBuilder
	{
		private readonly ContainerBuilder _containerBuilder = new ContainerBuilder();

		public IContainer Build()
		{
			_containerBuilder.RegisterGeneric(typeof(Repository<>)).As(typeof(IRepository<>)).InstancePerDependency();
			return _containerBuilder.Build();
		}
	}
}
