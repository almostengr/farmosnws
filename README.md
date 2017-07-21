# FarmOS NWS
Automated importing of National Weather Service (NWS) data into FarmOS.

## Purpose
The purpose of this project is to allow FarmOS to use data from the National
Weather Service to allow it to make better decisions as well as to log 
data from a trusted weather source. 

Bit Second noticed that some small farmers and gardeners do not have the 
financial resources to deploy many sensors for their FarmOS installation. 
However, by combining the data provide from the local NWS weather station and
using additional Drupal modules, FarmOS can be better automated with a lower
investment.

## System Requirements
* Drupal 7
* FarmOS
* Ubuntu Linux (May run on other Linux versions, but has only be tested with Ubuntu Linux 14.04)
* PHP
* Crontab or other task scheduler capable of running shell scripts

## Setup

### Clone the Repository
To get the latest release, clone this repository by running the command below
```shell
git clone https://github.com/bitsecondal/farmosnws.git
```

### Create Configuration File
Make a copy of the get_weather_config_ex.sh file. Update the variables located in the configuration
script file. 

```shell
get_weather.sh genconfig
```

The *feedsdir* location will need to be updated to the file system location that 
Drupal is checking to see if data files are available. 

The *location* variable will need to be updated to the location code for the location 
that you want data for.
* Go to the [XML data feeds](http://w1.weather.gov/xml/current_obs/) page on the NWS website.
* Select the state and click Find
* Find the location that is cloest to the area that you want to pull data for. 
* In the parenthesis next to the location, you will see a 4-character code. Copy this code.
* Place the 4-character code in the configuration file inside quotes.
* Save the configuration file. 

If you have multiple locations that you want to pull data for, you'll need to create a configuration 
file for each location and set up a scheduled task for each configuration file.  

### Schedule Script
To set up a cron job to run to automatically pull the latest weather data, you use the details and 
steps below. The National Weather Service updates the data hourly.

#### Linux/Ubuntu with Crontab
Update the paths mentioned to the location of your script and the location of your configuration 
file respectively. If you want to log the output of the script, also update the log location. 
```shell
24 * * * * (/path/to/drupal/sites/all/modules/farmosnws/get_weather.sh /path/to/drupal/sites/all/modules/farmosnws/config.sh) >> /var/log/get_weather.log 2>&1
```
If you don't want to log the output of the command, then use the command below. 
```shell
24 * * * * (/path/to/drupal/sites/all/modules/farmosnws/get_weather.sh /path/to/drupal/sites/all/modules/farmosnws/config.sh) >> /dev/null 2>&1
```

#### Windows with Task Scheduler
This script is not designed to work on Windows.

## Code Updates 
To get the latest version of this code, pull the latest release from the 
[FarmOS NWS GitHub Page](https://github.com/bitsecondal/farmosnws). 

Alternatively you can get the latest code by going to the directory that contains the code and running the commands below:
```shell
git checkout master
git pull origin master
```
 
## Author
Kenny Robinson, [Bit Second Tech](www.bitsecondtech.com)

## Bug Reports and Feature Enhancements
Bugs and enhancements will be tracked using the Issue tracker
on the [project repo](https://github.com/bitsecondal/farmosnws/issues). 

If you need to report a bug, please open a new issue on this repo. Include 
as much detail as possible including error messages or screenshots so that the issue can be replicated. 

## License 
Project is available under the MIT License. See LICENSE for more information.

## Additional Information
For more information about Bit Second Tech, please visit the [Bit Second Tech](http://www.bitsecondtech.com) website.

For more information about FarmOS, please visit the [FarmOS](http://www.farmos.org) website.

For more information about the National Weather Service (NWS), please visit the [NWS](http://www.weather.gov) website.


