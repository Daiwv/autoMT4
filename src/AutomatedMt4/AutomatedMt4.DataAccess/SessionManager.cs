using NHibernate;
using NHibernate.Tool.hbm2ddl;

namespace AutomatedMt4.DataAccess
{
	public class SessionManager
	{
		private readonly ISessionFactory _sessionFactory;
		private ISession _currentSession;

		public ISession CurrentSession { get { return _currentSession; } private set { _currentSession = value; } }

		public SchemaExport SchemaExport { get; set; }


		public SessionManager(ISessionFactory sessionFactory)
		{
			_sessionFactory = sessionFactory;
		}

		public SessionManager()
		{
			
		}

		public bool IsSessionOpened
		{
			get { return _currentSession != null && _currentSession.IsOpen; }
		}

		public ISession OpenSession()
		{
			if (!IsSessionOpened)
			{
				_currentSession = _sessionFactory.OpenSession();
				if (SchemaExport != null)
					SchemaExport.Execute(true, true, false, _currentSession.Connection, null);
			}
			return _currentSession;
		}

		public void CloseSession()
		{
			if (_currentSession != null && _currentSession.IsOpen)
			{
				_currentSession.Close();
			}
			_currentSession = null;
		}
	}
}
