<?php
$file = file_get_contents("php://stdin");

// Regex pattern to match single and multi-line comments
$pattern = '/(\/\/[^\n]*|\/\*[\s\S]*?\*\/)/';

// Find all the matches
preg_match_all($pattern, $file, $matches);

// Output the comments, removing leading whitespaces and preserving line structure
foreach ($matches[0] as $match) {
    echo preg_replace('/^\s+/m', '', $match) . "\n";
}
?>
