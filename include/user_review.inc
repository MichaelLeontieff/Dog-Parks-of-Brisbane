<?php

/*
 * user review function that creates user review from table data and creates
 * required microdata
 */
function userReview($name, $comment, $date, $rating)
{
    echo '<div class="userreview">';
    echo '<div class="userimage"></div>';
    echo '<h3>' . $name . ' said on the ' . $date . '...</h3>';
    echo '<p>' . $comment . '</p>';
    echo '<p>' . $rating . ' <i>out of</i> 5 Stars</p>';
    echo '</div>';

    // meta data
    // hidden through stylesheet

    echo '<div class="hiddenmeta" itemscope itemtype="http://schema.org/Park">';
    echo '<div itemprop="review" itemscope itemtype="http://schema.org/Review">';
    echo '<p itemprop="name">' . $rating . ' out of 5 stars</p>
            <p itemprop="author">' . $name . '</p>';

    echo '<div itemprop="reviewRating" itemscope itemtype="http://schema.org/Rating">';
    echo '<p itemprop="ratingValue">' . $rating . '</p>';
    echo '<p itemprop="bestRating">5</p>';
    echo '<p itemprop="worstRating">1</p>';
    echo '</div>';

    echo '<p itemprop="description">' . $comment . '</p>';
    echo '</div>';
    echo '</div>';

}

?>
