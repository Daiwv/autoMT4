using Autofac;
using AutomatedMt4.DataAccess;
using AutomatedMt4.DataAccess.Entities;
using MbUnit.Framework;

namespace AutomatedMt4.DI.Tests
{
	[TestFixture, Parallelizable(TestScope.Self)]
	public class DIContainerBuilderTests
	{
		[Test]
		public void Resolve_TypesFromContainerBuilderShouldBeResolvedCorrectly()
		{
			var container = new DIContainerBuilder().Build();
			var type = container.Resolve<IRepository<ExpertDetails>>();
		}
	}
}
