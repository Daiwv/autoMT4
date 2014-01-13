using AutomatedMt4.DataAccess.Entities;
using FluentNHibernate.Mapping;

namespace AutomatedMt4.DataAccess.Mappings
{
    public class ModifyOrderDetailsMap : ClassMap<ModifyOrderDetails>
    {
        public ModifyOrderDetailsMap()
        {
            Table("ModifyOrderDetails");
            Schema("AutomatedMt4");

            Id(x => x.Id);
            Map(x => x.OrderId);
            Map(x => x.UpdatedStopLoss);
            Map(x => x.UpdatedTakeProfit);
        }
    }
}
