using System.ComponentModel;
using System.ServiceProcess;

namespace AuthLogs
{
    [RunInstaller(true)]
    public partial class AuthLogsInstaller : System.Configuration.Install.Installer
    {
        ServiceInstaller serviceInstaller;
        ServiceProcessInstaller processInstaller;

        public AuthLogsInstaller()
        {
            InitializeComponent();
            serviceInstaller = new ServiceInstaller();
            processInstaller = new ServiceProcessInstaller();

            processInstaller.Account = ServiceAccount.LocalSystem;
            serviceInstaller.StartType = ServiceStartMode.Automatic;
            serviceInstaller.ServiceName = "AuthLogsService";
            Installers.Add(processInstaller);
            Installers.Add(serviceInstaller);
        }
    }
}
