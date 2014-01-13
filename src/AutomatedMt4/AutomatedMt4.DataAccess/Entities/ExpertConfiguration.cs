using FluentNHibernate.Data;

namespace AutomatedMt4.DataAccess.Entities
{
    public class ExpertConfiguration : Entity
    {
        public virtual int Id { get; set; }
        public virtual string Name { get; set; }
        public virtual int StopLoss { get; set; }
        public virtual int TakeProfit { get; set; }
        public virtual decimal OrderAmount { get; set; }
        public virtual int ModifyStopLoss { get; set; }
        public virtual int ModifyTakeProfit { get; set; }
    }
}
