using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(F6Ex2.Startup))]
namespace F6Ex2
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
