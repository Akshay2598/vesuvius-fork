<?php
/* $Id: server_import.php,v 1.1 2008-06-05 12:28:36 chamindra Exp $ */
// vim: expandtab sw=4 ts=4 sts=4:

require_once('./libraries/common.lib.php');

/**
 * Does the common work
 */
require('./libraries/server_common.inc.php');


/**
 * Displays the links
 */
require('./libraries/server_links.inc.php');

$import_type = 'server';
require('./libraries/display_import.lib.php');
/**
 * Displays the footer
 */
require('./libraries/footer.inc.php');
?>

