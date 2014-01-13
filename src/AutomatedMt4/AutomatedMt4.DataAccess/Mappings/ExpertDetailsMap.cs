using AutomatedMT4.Core.Enums;
using AutomatedMt4.DataAccess.Entities;
using FluentNHibernate.Mapping;

namespace AutomatedMt4.DataAccess.Mappings
{
    public class ExpertDetailsMap : ClassMap<ExpertDetails>
    {
        public ExpertDetailsMap()
        {
            Table("ExpertDetails");
            Schema("AutomatedMt4");

            Id(x => x.Id);
            Map(x => x.Pair);
            Map(x => x.State);
            Map(x => x.TimeFrame).CustomType<TimeFrame>();
            Map(x => x.CreatedOn);
            Map(x => x.BalanceOnCreate);
            Map(x => x.BalanceOnClose);
            Map(x => x.ClosedOn);
            Map(x => x.TrendType);
            Map(x => x.ExpertName);
            Map(x => x.Profit);
            Map(x => x.OrderId);
            Map(x => x.StopLoss);
            Map(x => x.TakeProfit);
        }
    }
}
