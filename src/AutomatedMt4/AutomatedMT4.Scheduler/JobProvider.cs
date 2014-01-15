using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

namespace AutomatedMT4.Scheduler
{
    public class JobProvider
    {
        public IList<Type> GetImplementedJobsTypes()
        {
            var result = new List<Type>();
            var aseembly = Assembly.LoadFrom("AutomatedMT4.Scheduler.dll");
            foreach (Type type in aseembly.GetTypes() )
            {
                if(type.GetInterfaces().FirstOrDefault(x=>x.Name == "IJob") != null)
                {
                    result.Add(type);
                }
          
            }
            return result;
        }
    }
}
