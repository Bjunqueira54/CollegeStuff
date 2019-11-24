using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Ficha7.Startup))]
namespace Ficha7
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
