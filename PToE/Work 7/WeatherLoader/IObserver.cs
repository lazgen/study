namespace WeatherLoader
{
    interface IObserver
    {
        string objectName { set; get; }

        void update(WeatherInfo info);
    }
}
