# Setup 

## System Requirements
* Drupal 7
* FarmOS
* Ubuntu Linux (May run on other Linux versions, but has only be tested with Ubuntu Linux 14.04 LTS)
* PHP 5
* Crontab or other task scheduler capable of running shell scripts

## Instructions

1) Clone this repository by running the command below
```shell
git clone https://github.com/bitsecondal/farmosnws.git
```

2) Install the module in Drupal

3) Go to the module configuration page.

4) Go to the [XML data feeds](http://w1.weather.gov/xml/current_obs/) page on the NWS website.

5) Select the state and click Find

6) Find the location that is closest to the area that you want to pull data for.

7) In the parenthesis next to the location, you will see a 4-character code. Copy this code.

8) Place the 4-character code on a line in the text box. If you have multiple locations that you
want to pull the data for, then enter each one on a separate line.

9) Enter the path where the weather files are to be saved on the server. This will be the same location
that the Feeds module will import the files from.

10) Click *Save configuration* on the form.

11) Go to the *Feeds importer* (Structure > Feeds importer) page

12) Create a new importer and name it.

13) Select the *XPath XML Parser* as the parser.

14) Enter each of the elements that you want to capture in the Parser Settings.

15) Configure the remainder of the settings for the Feeds Importer.

## Schedule Script
No scheduling has to be done. Weather data will be automatically be pulled when Drupal cron run. If 
necessary, adjust Drupal cron frequency or use [Elysia Cron](https://www.drupal.org/project/elysia_cron)
to run module specific cron.
 
## Get Weather Data via Shell Script (Advanced)
### Create Configuration File
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

If you have multiple locations that you want to pull data for, you will need to create a configuration 
file for each location and set up a scheduled task for each configuration file.  

## Schedule Script
To set up a cron job to run to automatically pull the latest weather data, you use the details and 
steps below. The National Weather Service updates the data hourly.

## Linux/Ubuntu with Crontab
Update the paths mentioned to the location of your script and the location of your configuration 
file respectively. If you want to log the output of the script, also update the log location. 
```shell
24 * * * * (/path/to/drupal/sites/all/modules/farmosnws/get_weather.sh /path/to/drupal/sites/all/modules/farmosnws/config.sh) >> /var/log/get_weather.log 2>&1
```

