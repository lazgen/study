using Newtonsoft.Json.Linq;

namespace WeatherLoader
{
    class ParserA
    {
        public WeatherInfo parse(string info)
        {
            if (info.Length == 0)
                return new WeatherInfo();

            WeatherInfo weather = new WeatherInfo();

            JObject o = JObject.Parse(info);

            weather.town = (string)o["name"];
            weather.temp = (string)o["main"]["temp"];
            weather.pressure = (string)o["main"]["pressure"];
            weather.humidity = (string)o["main"]["humidity"];
            weather.description = (string)o["weather"][0]["main"] + ": " + (string)o["weather"][0]["description"];

            return weather;
        }
    }
}
