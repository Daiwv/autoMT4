using System;
using FluentNHibernate.Data;

namespace AutomatedMt4.DataAccess.Entities
{
    public class ModifyOrderDetails : Entity
    {
        public virtual int Id { get; set; }
        public virtual int OrderId { get; set; }
        public virtual double UpdatedTakeProfit { get; set; }
        public virtual double UpdatedStopLoss { get; set; }
        public virtual DateTime CreatedOn { get; set; }
    }
}
