namespace WeatherLoader
{
    interface IObservable
    {
        void subscribe(IObserver obs);

        void unsubscribe(IObserver obs);

        void notify(IObserver observer, WeatherInfo data);
    }
}
