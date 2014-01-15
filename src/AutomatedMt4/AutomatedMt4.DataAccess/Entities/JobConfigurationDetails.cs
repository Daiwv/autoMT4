using FluentNHibernate.Data;

namespace AutomatedMt4.DataAccess.Entities
{
	public class JobConfigurationDetails : Entity
	{
		public virtual int Id { get; set; }
		public virtual string Name { get; set; }
		public virtual int TriggerTimeInSec { get; set; }
	}
}
