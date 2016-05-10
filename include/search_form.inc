<?php

require 'formelements.inc';

// suburb input field
suburb("suburb", "Suburb");

// park name input field
loose_input_field("parkname", "Park Name", "text");

// rating input field
rating("rating", "Rating");

// geolocation input field
geoLocation("geolocation", "Use GeoLocation");
geo_input_field("lat", "Latitude", "text", "geolatfield");
geo_input_field("lon", "Longitude", "text", "geolonfield");

echo '<input type="submit" class="submitbutton" value="Fetch!">';


?>