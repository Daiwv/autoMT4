using System;
using AutomatedMT4.Core.Enums;
using FluentNHibernate.Data;

namespace AutomatedMt4.DataAccess.Entities
{
    public class ExpertDetails : Entity
    {
        public virtual int Id { get; set; }
        public virtual string Pair { get; set; }
        public virtual TimeFrame TimeFrame { get; set; }
        public virtual DateTime CreatedOn { get; set; }
        public virtual DateTime? ClosedOn { get; set; }
        public virtual string State { get; set; }
        public virtual double BalanceOnCreate { get; set; }
        public virtual double? BalanceOnClose { get; set; }
        public virtual string TrendType { get; set; }
        public virtual string ExpertName { get; set; }
        public virtual double Profit { get; set; }
        public virtual int OrderId { get; set; }
        public virtual double StopLoss { get; set; }
        public virtual double TakeProfit { get; set; }
    }
}
