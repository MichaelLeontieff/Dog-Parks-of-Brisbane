<?php

function userReview($name, $rating, $comment)
{
    echo '<div class="userreview">';
    echo '<div class="userimage"></div>';
    echo '<h3>' . $name . ' says...</h3>';
    echo '<p>' . $comment . '</p>';
    echo '<p>' . $rating . ' <i>out of</i> 5 Stars</p>';
    echo '</div>';

    // meta data

    echo '<div class="hiddenmeta" itemscope itemtype="http://schema.org/Park">';
    echo '<div itemprop="review" itemscope itemtype="http://schema.org/Review">';
    echo '<meta itemprop="name">' . $rating . ' out of 5 stars</meta> -
        by <span itemprop="author">' . $name . '</span>';

    echo '<div itemprop="reviewRating" itemscope itemtype="http://schema.org/Rating">';
    echo '<span itemprop="ratingValue">' . $rating . '</span>';
    echo '<span itemprop="bestRating">5</span>';
    echo '<span itemprop="worstRating">1</span>';
    echo '</div>';

    echo '<span itemprop="description">' . $comment . '</span>';
    echo '</div>';
    echo '</div>';

}

?>
