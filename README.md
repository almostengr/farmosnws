# farmosnws
A Drupal module to allow automated importing of National Weather Service (NWS) data into FarmOS.

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
* Ubuntu Linux (May run on other Linux versions, but has only be tested with Ubuntu Linux 14.04 LTS)
* PHP 5
* Crontab or other task scheduler capable of running shell scripts

## Setup

### Clone the Repository
Clone this repository by running the command below
```shell
git clone https://github.com/bitsecondal/farmosnws.git
```

### Get Weather Data via Drupal 
* Install the module in Drupal 
* Go to the module configuration page.
* Go to the [XML data feeds](http://w1.weather.gov/xml/current_obs/) page on the NWS website.
* Select the state and click Find
* Find the location taht is closest to the area that you want to pull data for.
* In the parenthesis next to the location, you will see a 4-character code. Copy this code.
* Place the 4-character code on a line in the text box. If you have multiple locations that you 
want to pull the data for, then enter each one on a separate line.
* Enter the path where the weather files are to be saved on the server. This will be the same location
that the Feeds module will import the files from.
* Click *Save configuration* on the form.
* Go to the *Feeds importer* (Structure > Feeds importer) page
* Create a new importer and name it.
* Select the *XPath XML Parser* as the parser.
* Enter each of the elements that you want to capture in the Parser Settings.
* Configure the remainder of the settings for the Feeds Importer.

#### Schedule Script
No scheduling has to be done. Weather data will be automatically be pulled when Drupal cron run. If 
necessary, adjust Drupal cron frequency or use [Elysia Cron](https://www.drupal.org/project/elysia_cron)
to run module specific cron.
 
### Get Weather Data via Shell Script (Advanced)
#### Create Configuration File
Make a copy of the get_weather_config_ex.sh file. Update the variables located in the configuration
script file. 

The *feedsdir* location will need to be updated to the file system location that 
Drupal is checking to see if data files are available. 

The *location* variable will need to be updated to the location code for the location 
that you want data for.
* Go to the [XML data feeds](http://w1.weather.gov/xml/current_obs/) page on the NWS website.
* Select the state and click Find
* Find the location that is closest to the area that you want to pull data for. 
* In the parenthesis next to the location, you will see a 4-character code. Copy this code.
* Place the 4-character code in the configuration file inside quotes.
* Save the configuration file. 

If you have multiple locations that you want to pull data for, you'll need to create a configuration 
file for each location and set up a scheduled task for each configuration file.  

#### Schedule Script
To set up a cron job to run to automatically pull the latest weather data, you use the details and 
steps below. The National Weather Service updates the data hourly.

##### Linux/Ubuntu with Crontab
Update the paths mentioned to the location of your script and the location of your configuration 
file respectively. If you want to log the output of the script, also update the log location. 
```shell
24 * * * * (/path/to/drupal/sites/all/modules/farmosnws/get_weather.sh /path/to/drupal/sites/all/modules/farmosnws/config.sh) >> /var/log/get_weather.log 2>&1
```

## Code Updates 
To get the latest version of this code, pull the latest release from the 
[FarmOS NWS GitHub Page](https://github.com/bitsecondal/farmosnws). 

Alternatively you can get the latest code by going to the directory that contains the code and running the command below:
```shell
git pull origin master
```
 
## Author
Kenny Robinson, Bit Second Tech (www.bitsecondtech.com)

## Bug Reports and Feature Enhancements
Bugs and enhancements will be tracked using the Issue tracker
on the [project repo](https://github.com/bitsecondal/farmosnws/issues). 

If you need to report a bug, please open a new issue. Include 
as much detail as possible, including screenshots and error messages, so that the issue can be replicated. 

## License 
Project is available under the MIT License. See LICENSE for more information.

## Additional Information
For more information about Bit Second Tech, please visit the
[Bit Second Tech](http://www.bitsecondtech.com) website.

For more information about FarmOS, please visit the [FarmOS](http://www.farmos.org) website.

For more information about the National Weather Service (NWS), please visit the 
[NWS](http://www.weather.gov) website.

