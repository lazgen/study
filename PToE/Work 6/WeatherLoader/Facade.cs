﻿namespace WeatherLoader
{
    class Facade : IFacade
    {
        private Loader loader = new Loader();
        private Parser parser = new Parser();
        private WeatherInfo weather = new WeatherInfo();

        public WeatherInfo updateWeatherInfo(string town)
        {
            loader.town = town;
            weather = parser.parse(loader.load());

            return weather;
        }
    }
}
