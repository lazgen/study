namespace WeatherLoader
{
    class Facade : IFacade
    {
        private Loader loader = new Loader();
        private Parser parser = new Parser();
        private WeatherInfo weather = new WeatherInfo();

        public void updateWeatherInfo()
        {
            weather = parser.parse(loader.load());
        }

        public WeatherInfo weatherInfo
        {
            get { return weather; }
        }
    }
}
