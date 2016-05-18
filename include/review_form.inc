<?php

/*
 * review form implementation
 */

include 'formelements.inc';

commentField('comment');
radioRating('rating');
echo '<input type="submit" value="Post" id="submitbutton">';

?>

