using System.Collections.Generic;

namespace AutomatedMt4.DataAccess
{
    public interface IRepository<T>
    {
        T Get(object id);
        void Save(T value);
        void Update(T value);
        void Delete(T value);
        IList<T> GetAll();
    }
}
