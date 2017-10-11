using System;
using System.Web.Script.Serialization;

namespace WeatherLoader
{
    class Parser
    {
        public WeatherInfo parse(string info)
        {
            WeatherInfo weather = new JavaScriptSerializer().Deserialize<WeatherInfo>(info);
            Console.WriteLine("{0} {1} {2} {3}", weather.current_date, weather.current_time, weather.current_temp, weather.description);
            return weather;
        }
    }
}
