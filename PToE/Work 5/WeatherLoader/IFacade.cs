namespace WeatherLoader
{
    interface IFacade
    {
        WeatherInfo weatherInfo { get; }
        void updateWeatherInfo(string town);
    }
}
