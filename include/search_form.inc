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

echo '<input type="submit" class="submitbutton" value="Fetch!">';


?>