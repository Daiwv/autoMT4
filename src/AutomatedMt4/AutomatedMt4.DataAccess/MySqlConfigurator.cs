using System.Reflection;
using FluentNHibernate.Cfg;
using FluentNHibernate.Cfg.Db;
using NHibernate;
using NHibernate.Cfg;
using NHibernate.Tool.hbm2ddl;

namespace AutomatedMt4.DataAccess
{
	public class MySqlConfigurator
	{
		private Configuration _config;
		private ISessionFactory _sessionFactory;

		public virtual Assembly MappingFilesAssembly { get; set; }
		public virtual SchemaExport SchemaExport { get; protected set; }
		protected Configuration Config { get { return _config; } }


		public virtual void Configure()
		{
			_config = GetConfig();
		}

		public virtual ISessionFactory BuildSessionFactory()
		{
			if (_sessionFactory == null)
			{
				Configure();
				_sessionFactory = _config.BuildSessionFactory();
			}
			return _sessionFactory;
		}

	
		protected virtual Configuration GetConfig()
		{
			return Fluently.Configure().Database(MySQLConfiguration.Standard
																	 .ConnectionString(c => c
																								.Server("localhost")
																								.Database("AutomatedMt4")
																								.Username("root")
																								.Password("")))
							 .Mappings(m => m.FluentMappings.AddFromAssembly(Assembly.GetExecutingAssembly()))
							 .ExposeConfiguration(DropCreateSchema)
							 .BuildConfiguration();
		}

		private static void DropCreateSchema(Configuration cfg)
		{
			new SchemaUpdate(cfg).Execute(false, true);
		}
	}
}
