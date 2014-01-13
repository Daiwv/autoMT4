using FluentNHibernate.Data;
using MbUnit.Framework;

namespace AutomatedMt4.DataAccess.DataTests
{
    [TestFixture, Parallelizable(TestScope.Self)]
    public abstract class BaseDataAccessTests<T> where T : Entity, new()
    {
        private IRepository<T> _repository = new Repository<T>();

        [Test]
        public void Save_ShouldSaveRecordToRepository()
        {
            var oldCount = _repository.GetAll().Count;
            var entity = new T();
            _repository.Save(entity);
            Assert.AreEqual(oldCount + 1, _repository.GetAll().Count);
        }

        [Test]
        public void Delete_ShouldDeleteAllRecords()
        {
            foreach (var entity in _repository.GetAll())
            {
                _repository.Delete(entity);
            }
        }
    }
}
