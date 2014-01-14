using AutomatedMt4.DataAccess.Entities;
using FluentNHibernate.Mapping;

namespace AutomatedMt4.DataAccess.Mappings
{
	public class JobConfigurationDetailsMap : ClassMap<JobConfigurationDetails>
	{
		public JobConfigurationDetailsMap()
		{
			Table("JobConfigurationDetails");
			Schema("AutomatedMt4");

			Id(x => x.Id);
			Map(x => x.Name);
			Map(x => x.TriggerTime);
		}
	}
}
