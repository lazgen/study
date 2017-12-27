namespace WeatherLoader
{
    class FacadeB : IFacade
    {
        private LoaderB loader = new LoaderB();
        private ParserB parser = new ParserB();
        private WeatherInfo weather = new WeatherInfo();

        public WeatherInfo updateWeatherInfo(string town)
        {
            loader.town = town;
            weather = parser.parse(loader.load());

            return weather;
        }
    }
}
