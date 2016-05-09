<?php

function userReview($name, $rating, $comment)
{
    echo '<div class="userreview">';
    echo '<div class="userimage"></div>';
    echo '<h3>' . $name . ' says...</h3>';
    echo '<p>' . $comment . '</p>';
    echo '<p>' . $rating . ' <i>out of</i> 5 Stars</p>';
    echo '</div>';
}

?>
