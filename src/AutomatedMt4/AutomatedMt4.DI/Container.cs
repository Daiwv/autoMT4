﻿using Autofac;

namespace AutomatedMt4.DI
{
	public static class Container
	{
		private static IContainer _instance;

		public static IContainer GetInstance()
		{
			if (_instance == null)
				BootStrap();

			return _instance;
		}

		internal static void BootStrap()
		{
			_instance = new DIContainerBuilder().Build();
		}

		public static T Resolve<T>()
		{
			return _instance.Resolve<T>();
		}
	}
}
