namespace WeatherLoader
{
    class Facade1 : IFacade
    {
        private Loader1 loader = new Loader1();
        private Parser1 parser = new Parser1();
        private WeatherInfo weather = new WeatherInfo();

        public WeatherInfo updateWeatherInfo(string town)
        {
            loader.town = town;
            weather = parser.parse(loader.load());

            return weather;
        }
    }
}
