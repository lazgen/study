namespace WeatherLoader
{
    class FacadeA : IFacade
    {
        private LoaderA loader = new LoaderA();
        private ParserA parser = new ParserA();
        private WeatherInfo weather = new WeatherInfo();

        public WeatherInfo updateWeatherInfo(string town)
        {
            loader.town = town;
            weather = parser.parse(loader.load());

            return weather;
        }
    }
}
