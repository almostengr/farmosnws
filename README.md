# FarmOS NWS
Automated importing of National Weather Service (NWS) data into FarmOS.

## Purpose
The purpose of this project is to allow FarmOS to use data from the National
Weather Service to allow it to make better decisions as well as to log 
data from a trusted weather source.

Using data from the National Weather Service reduces the cost to get a FarmOS
installation going as temperature, rain, humidity and other sensors do not
have to be purchased. Furthermore, it reduces the maintenance costs by 
reducing the amount of infrastructure required to maintain the farm or garden.

## System Requirements
* Drupal 7
* FarmOS
* Internet connection

## Installation

### Clone the Repository
To get the latest release, clone this repository by running the command below
```shell
git clone https://github.com/almostengr/farmosnws.git
```

Within your Drupal site, enable the FarmOS NWS and FarmOS NWS Feeds Importer 
modules from the Modules page.

### Configure FarmOS NWS
After enabling the modules, go to the FarmOS NWS configuration page (Admin >
Configuration > Web Services > FarmOS NWS Settings). Enter the file system
location, weather locations that you would like weather imported for, 
measurement units, and whether you want to keep files after they have been
loaded. When done, click Save.

### Configure Feed Importer
Within your Drupal site, go to the feed importer page (Structure > Feeds 
Importers > Log: NWS Observation). In the Fetcher section, set the upload 
directory to the same directory that you defined in the Configure FarmOS NWS 
section. When done, click Save.

## Uninstallation
Within your Drupal site, go to the Modules page and disable FarmOS NWS and 
FarmOS NWS Importer modules and click Save Configuration. Then go to the 
Uninstall page (Modules > Uninstall), select each module, and click Uninstall.

If you uninstall the modules, the data that was imported by the modules WILL 
NOT be removed. If you wish to remove the data that was imported, you will have 
to manually remove each entry.

## Code Updates 
To get the latest version of this code, pull the latest release from the 
[FarmOS NWS GitHub Page](https://github.com/almostengr/farmosnws). 

Alternatively you can get the latest code by going to the directory that contains 
the code and running the commands below:
```shell
git checkout 7.x-2.x
git pull origin 7.x-2.x
```
 
### Development Version
To get the latest development version of the code, pull the latest dev release from
the [https://github.com/almostengr/farmosnws/tree/7.x-2.x-dev](//github.com/almostengr/farmosnws/tree/7.x-2.x-dev).
Development versions of the code may not be stable and are not recommended to be
used in Production environments.

Alternatively, you can get the latest development code by going to the directory 
that contains the code and running the commands below:
```shell
git checkout 7.x-2.x-dev
git pull origin 7.x-2.x-dev
```

## Author
Kenny Robinson, [@almostengr](https://twitter.com/almostengr)
[http://thealmostengineer.com](http://thealmostengineer.com)

## Additional Information
Bugs and enhancements will be tracked using the Issue tracker
on the [project repo](https://github.com/almostengr/farmosnws/issues). 

Project is available under the MIT License. See LICENSE for more information.

For more information about FarmOS, please visit the 
[FarmOS](http://www.farmos.org) website.

For more information about the National Weather Service (NWS), please visit
the [NWS](http://www.weather.gov) website.


