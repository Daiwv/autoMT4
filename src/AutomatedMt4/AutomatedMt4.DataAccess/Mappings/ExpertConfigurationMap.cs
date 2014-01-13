using AutomatedMt4.DataAccess.Entities;
using FluentNHibernate.Mapping;

namespace AutomatedMt4.DataAccess.Mappings
{
    public class ExpertConfigurationMap : ClassMap<ExpertConfiguration>
    {
        public ExpertConfigurationMap()
        {
            Table("ExpertConfiguration");
            Schema("AutomatedMt4");

            Id(x => x.Id);
            Map(x => x.ModifyStopLoss);
            Map(x => x.ModifyTakeProfit);
            Map(x => x.Name);
            Map(x => x.OrderAmount);
            Map(x => x.StopLoss);
            Map(x => x.TakeProfit);
        }
    }
}
