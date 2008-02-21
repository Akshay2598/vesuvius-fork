<?php


/**
 * This function shows a form to add main category and submit values to a function in the main.inc
 * @access public
 * @return void
 */

function shn_service_addmain_form() {
	$extra_opts['req'] = true;
	shn_form_fopen('addmain_form_submit');
	shn_form_fsopen(_t('Enter details to the catalogue'));
	shn_form_text(_t("Module Name   : "), 'main_cat_name', 'size="50"', $extra_opts);
	shn_form_text(_t("Feed Confkey   : "), 'description', 'size="50"');
	shn_form_text(_t("Respective FeedNumber	:"), 'FeedNumber', 'size="50"');

	shn_form_fsclose();
	shn_form_fsopen(_t('Value'));
	shn_form_text(_t(" "), 'keyword', 'size="50"', array (
		('Enter a keyword which will help you to search purticular catalogue/Item easily.'
	)));

	shn_form_fsclose();
	shn_form_submit(_t("Add"));
	shn_form_fclose();

}

/**
 * This function validates the values entered in add main form.
 *This function is called by shn_service_addmain_form_submit() in main.inc
 * @access private
 * @return boolean
 */
function _shn_service_validate_addmainform() {
	$error_flag = false;
	clean_errors();

	//this checks whether name entered in the add main form
	if (trim($_POST['main_cat_name']) == null) {
		add_error(_t("Please Enter the Moduel Name"));
		$error_flag = true;
	}
	return $error_flag;
}

/**
 * This function shows the result after processing the POST values from shn_service_addmain_form().
 *This function is called by shn_service_addmain_form_submit() in main.inc
 * @access private
 * @return void
 */
function _shn_service_addmain_form_result() {
	global $global;
	$db = $global["db"];
	$parentid = $parentid +2;
	$idincrement = trim($_POST['FeedNumber']);

	//here the primery key has to be incremented in sequence

	$name = trim($_POST['main_cat_name']);
	$description = trim($_POST['description']);
	$keyword = trim($_POST['keyword']);
	$id = shn_create_uuid("catalogue");

	/*echo " entered 1=> $name";
	echo " entered 2=> $description";
	echo " entered 3=> $keyword";
	echo " entered 4=> $id";
	echo " increment ---> $idincrement";
	  */

	//this is SQL query for entering and saving data in config_altered table  given

	$q = "INSERT INTO `config_altered` (" .
	"`module_id` ,`confkey` ,`value` ,`confkeyID` ,`visibility`) VALUES ('$name','$description','$keyword','$idincrement','1')";

	$res = $db->Execute($q);
	if ($res == true) {
?>
	<div id="result_msg">
	<?php print $name." was succesfully saved in the database.";?>
	</div>
	<?php


	} else {
?>
	<div id="result_msg">
	<?php print "Your Operation Aborted. <b>config_altered</b> table not found in the Database."; ?>
	</div>
	<?php


	}
}

/**
 * This function shows a form to add a sub category. It calls to a function in lib_cs.inc and submit the result to addsub_form1_submit.
 * @access public
 * @return void
 */

/* All fucntions commented

function shn_service_addsub_form1() {
	require_once ("lib_cs.inc");
	$form_opts['name'] = 'subcat';

	shn_form_fopen("addsub_form1_submit", null, $form_opts);
	$max_depth = get_max_depth();
	shn_sub_cat($max_depth, 'subcat', '', true);
	shn_form_fclose();

	print "<br><b>Do a keyword search to find the catalogue.</b>";
	shn_form_fopen("keyword_search");
	shn_form_fsopen(_t('Keyword Search'));
	shn_form_text(_t(" "), 'search_keyword', 'size="50"', array (
		'help' => _t('Search for the catalogue using a keyword and then add catalogues/Items under it.'
	)));
	shn_form_hidden(array (
		'type' => 'sub_catalogue'
	));
	shn_form_submit(_t("Search"));
	shn_form_fsclose();
	shn_form_fclose();

}

/**
 * This function shows a form to add a sub category.Submit the result to addsub_form2_submit() in main.inc.
 * @access private
 * @return void
 */

/* All fucntions commented
 *  

function _shn_service_addsub_form1_result($is_keyword_search = false) {
	global $global;
	$db = $global["db"];

	require_once ("lib_cs.inc");
	if ($is_keyword_search == false) {
		$parent_id = get_itemid();
	} else {
		$parent_id = trim($_REQUEST['id']);
	}

	$extra_opts['req'] = true;
	shn_form_fopen("addsub_form2_submit");
	shn_form_fsopen(_t('Sub Catalogue Details'));
	shn_form_text(_t("Name   : "), 'sub_cat_name', 'size="50"', $extra_opts);
	shn_form_text(_t("Description   : "), 'sub_description', 'size="50"', null);
	shn_form_fsclose();
	shn_form_fsopen(_t('Keyword'));
	shn_form_text(_t(" "), 'sub_keyword', 'size="50"', array (
		'help' => _t('Enter a keyword which will help you to search purticular catalogue/Item easily.'
	)));
	shn_form_fsclose();

	//the parent ID is submitted as a hidden variable
	$parent_id_array = array (
		'0' => $parent_id
	);
	shn_form_hidden($parent_id_array);

	shn_form_submit(_t("Add"));
	shn_form_fclose();
}

/**
 * This function shows the result after processing the POST values from _shn_service_addsub_form1_result().
 *This function is called by shn_service_addsub_form2_submit() in main.inc
 * @access private
 * @return void
 */

//these funcitons not used till

function _shn_service_addsub_form2_result() {
	global $global;
	$db = $global["db"];

	require_once ("lib_cs.inc");
	$parent_id = get_itemid();

	$sub_cat_name = trim($_POST['sub_cat_name']);
	$sub_description = trim($_POST['sub_description']);
	$sub_keyword = trim($_POST['sub_keyword']);
	$id = shn_create_uuid("catalogue");
	$q = "insert into ct_catalogue (parentid,ct_uuid,name,description,keyword) values('$parent_id','$id','$sub_cat_name','$sub_description','$sub_keyword')";
	$res = $db->Execute($q);

	if ($res == true) {
?>
	<div id="result_msg">
	<?php echo $sub_cat_name." was succesfully saved in the database.";?>
	</div>
	<?php


	} else {
?>
	<div id="result_msg">
	<?php print "Your Operation Aborted. <b>ct_catalogue</b> table not found in the Database."; ?>
	</div>
	<?php


	}

}

/**
 * This function shows a form to add Measurement Unit
 * @access public
 * @return void
 */
function shn_service_addunit_form() {
	global $global;
	$db = $global["db"];

	$option_array = array ();

	$query = "select unit_type_uuid,name from ct_unit_type ";
	$res = $db->Execute($query);
	$option_array['none'] = '----Select Unit type----';
	while (!$res == NULL && !$res->EOF) {
		$option_array[$res->fields['unit_type_uuid']] = $res->fields['name'];
		$res->MoveNext();
	}

	if ($option_array == null) {
		shn_form_fopen(null);
		shn_form_fsopen(_t("Information"));
?>
    <p><?= _t('There is no any Measurement Unit category found. '); ?><a href="index.php?mod=cs&act=addunittype">Add Unit category</a><?= _t(' First'); ?></p>
    
    <?php


		shn_form_fsclose();
		shn_form_fclose();
	} else {
		$extra_opts['req'] = true;
		$form_opts['name'] = "select_unit_type_form";
		shn_form_fopen("addunit_select_utype_submit", null, $form_opts);
		shn_form_fsopen(_t("Select Measurement Unit Type"));
		$select_opts = 'onChange="changeform()"';
		shn_form_select($option_array, '', 'unit_type', $select_opts, null);
		shn_form_fsclose();
		shn_form_fclose();
	}

}

function _shn_service_utype_select_submit_result() {
	global $global;
	$db = $global["db"];

	$unit_type_id = trim($_POST['unit_type']);

	$query = "select name from ct_unit where unit_type_uuid ='$unit_type_id' and base_flag ='1'";
	$res = $db->Execute($query);

	$base_unit_name = $res->fields['name'];

	shn_form_fopen("addunit_form_submit");
	shn_form_fsopen(_t('Measurement Unit'));
	$extra_opts['req'] = true;
	shn_form_text(_t("Unit : "), 'unit_name', 'size="50"', $extra_opts);
	$extra_opts['value'] = $base_unit_name;
	$extra_opts['req'] = false;
	shn_form_text(_t("Base Unit : "), 'base_unit', 'size="5" readonly=true', $extra_opts);

	shn_form_text(_t("Multiplier : "), 'multiplier', 'size="50"', array (
		'req' => 'true',
		'help' => _t('Enter the Multiplier of the entered Unit to the base unit of the Unit Type. Eg: Unit = g, Base unit=kg, Multiplier=0.001 (g=kg*0.001)'
	)));
	shn_form_fsclose();

	$unit_id_array = array (
		'unit_type_id' => $unit_type_id
	);
	shn_form_hidden($unit_id_array);

	shn_form_submit(_t("Save"));

	shn_form_fclose();

}

/**
 * This function shows the result after processing the POST values from shn_service_addunit_form().
 *This function is called by shn_service_addunit_form_submit() in main.inc
 * @access private
 * @return void
 */

function _shn_service_addunit_form_result() {
	global $global;
	$db = $global["db"];

	$unit_name = trim($_POST['unit_name']);
	$multiplier = trim($_POST['multiplier']);
	$unit_type_id = trim($_POST['unit_type_id']);

	$unit_id = shn_create_uuid("unit");
	$query = "insert into ct_unit(unit_type_uuid,unit_uuid,name,base_flag,multiplier) values('$unit_type_id','$unit_id','$unit_name','0',$multiplier)";
	$res = $db->Execute($query);

	if ($res == true) {
?>
	<div id="result_msg">
	<?php echo $unit_name." was succesfully saved in the Database."; ?>
	</div>
	<?php


	} else {
?>
	<div id="result_msg">
	<?php print "Your Operation was not successfully completed. Found a Problem with Database.";?>
	</div>
	<?php


	}

}

function shn_service_additem_form1() {
	global $global;
	$db = $global["db"];
	require_once ("lib_cs.inc");
	$form_opts['name'] = 'subcat';

	shn_form_fopen("additem_form1_submit", null, $form_opts);
	$max_depth = get_max_depth();
	shn_sub_cat($max_depth, 'subcat', '', true);
	shn_form_fclose();

	$query = "select name,ct_uuid from ct_catalogue where parentid='0' ";
	$res = $db->Execute($query);
	if ($res == true) {
		print "<br><b>Do a keyword search to find the catalogue.</b>";
		shn_form_fopen("keyword_search");
		shn_form_fsopen(_t('Keyword Search'));
		shn_form_text(_t(" "), 'search_keyword', 'size="50"', array (
			'help' => _t('Search for the catalogue using a keyword and then add catalogues/Items under it.'
		)));
		shn_form_hidden(array (
			'type' => 'item'
		));
		shn_form_submit(_t("Search"));
		shn_form_fsclose();
		shn_form_fclose();
	}
}

function shn_service_additem_form1_result($is_keyword_search = false) {
	global $global;
	$db = $global["db"];
	require_once ("lib_cs.inc");
	if ($is_keyword_search == false) {
		$parent_id = get_itemid();
	} else {
		$parent_id = trim($_REQUEST['id']);
	}

	$option_array = array ();
	$query = "select unit_type_uuid,name from ct_unit_type ";
	$res = $db->Execute($query);
	$option_array['none'] = '----Select Unit type----';
	while (!$res == NULL && !$res->EOF) {
		$option_array[$res->fields['unit_type_uuid']] = $res->fields['name'];
		$res->MoveNext();
	}

	$form_opts['name'] = "select_unit_type_form1";
	$extra_opts['req'] = true;
	shn_form_fopen("additem_form2_submit", null, $form_opts);
	shn_form_fsopen(_t('Item Details'));
	shn_form_text(_t("Name   : "), 'itemname', 'size="50"', $extra_opts);
	shn_form_text(_t("Description   : "), 'item_description', 'size="50"', null);
	shn_form_fsclose();

	shn_form_fsopen(_t('Keyword'));
	shn_form_text(_t(" "), 'item_keyword', 'size="50"', array (
		'help' => _t('Enter a keyword which will help you to search purticular catalogue/Item easily.'
	)));
	shn_form_fsclose();

	$select_opts = 'onChange=change_units(this.options[this.selectedIndex].value)';
	shn_form_fsopen(_t('Measurement Type'));
	shn_form_select($option_array, _t('Measurement Type :'), 'measurement_type', $select_opts, null);
	shn_form_fsclose();

	shn_form_fsopen(_t('Measurement Unit'));
	shn_form_multi_select('unit_select', $myoptions, _t("Unit :"), 'size=5 multiple="multiple"');
	shn_form_fsclose();

	$parent_id_array = array (
		'0' => $parent_id
	);
	shn_form_hidden($parent_id_array);

	shn_form_submit(_t("Add"));
	shn_form_fclose();

}

function shn_service_additem_form2_result() {

	global $global;
	$db = $global["db"];

	$items_saved_ok = false;
	$all_units_saved_ok = false;
	$save_failed_units = array ();

	require_once ("lib_cs.inc");
	$parent_id = get_itemid();

	$item_name = trim($_POST['itemname']);
	$description = trim($_POST['item_description']);
	$item_keyword = trim($_POST['item_keyword']);

	$id = shn_create_uuid("catalogue");
	$q = "insert into ct_catalogue (parentid,ct_uuid,name,description,keyword,final_flag) values('$parent_id','$id','$item_name','$description','$item_keyword','1')";
	$res = $db->Execute($q);

	if ($res == true) {
		$items_saved_ok = true;
	}

	$unit_selected = $_POST["unit_select"];
	$num = sizeof($unit_selected);

	for ($i = 0; $i < $num; $i++) {
		$temp = $unit_selected[$i];
		$q = "insert into ct_cat_unit (ct_uuid,unit_uuid) values('$id','$temp')";
		$res = $db->Execute($q);
		if ($res == false) {
			array_push($save_failed_units, $temp);
		}
	} //end of for

	if ($save_failed_units == null) {
		$all_units_saved_ok = true;
	} else {
		$all_units_saved_ok = false;
	}

	if ($items_saved_ok == true && $all_units_saved_ok == true) {
?>
			<div id="result_msg">
			<?php print $item_name." was succesfully saved in the Database.";?>
			</div>
			<?php


	}
	elseif ($items_saved_ok == true && $all_units_saved_ok == false) {
		$del_query = "delete from ct_catalogue where ct_uuid = '$id' ";
		$res = $db->Execute($del_query);
?>
			<div id="result_msg">
			<?php print "Your Operation Aborted. <b>ct_cat_unit</b> table not found in the Database."; ?>
			</div>
			<?php


	}
	elseif ($items_saved_ok == false && $all_units_saved_ok == true) {
		$del_query = "delete from ct_cat_unit where ct_uuid = '$id' ";
		$res = $db->Execute($del_query);
?>
			<div id="result_msg">
			<?php print "Your Operation Aborted. <b>ct_catalogue</b> table not found in the Database."; ?>
			</div>
			<?php


	} else {
?>
			<div id="result_msg">
			<?php print "Your Operation Aborted. <b>ct_catalogue</b> and <b>ct_cat_unit</b> tables not found in the Database."; ?>
			</div>
			<?php


	}

}

function shn_service_add_unit_type_form() {
	$extra_opts['req'] = true;
	shn_form_fopen("addunitform_submit");
	shn_form_fsopen(_t('Unit Type Details'));
	shn_form_text(_t("Name   : "), 'unit_type_name', 'size="50"', $extra_opts);
	shn_form_text(_t("Description   : "), 'unit_type_description', 'size="50"', null);
	shn_form_fsclose();

	shn_form_fsopen(_t('Base Unit Details'));
	shn_form_text(_t("Name   : "), 'base_unit_name', 'size="50"', array (
		'req' => 'true',
		'help' => _t('Specify a base unit here. Eg: Unit Type - Mass, Base Unit- kg'
	)));
	shn_form_fsclose();

	shn_form_submit(_t("Add"));
	shn_form_fclose();
}

function _shn_service_add_unit_type_form_result() {
	global $global;
	$db = $global["db"];

	$unit_type_saved_ok = false;
	$base_unit_saved_ok = false;

	$unit_type_name = trim($_POST['unit_type_name']);
	$description = trim($_POST['unit_type_description']);
	$base_unit_name = trim($_POST['base_unit_name']);

	$unit_type_id = shn_create_uuid("unit_type");
	$q = "insert into ct_unit_type (unit_type_uuid,name,description) values('$unit_type_id','$unit_type_name','$description')";
	$res = $db->Execute($q);
	if ($res == true) {
		$unit_type_saved_ok = true;
	}

	$unit_id = shn_create_uuid("unit");
	$query = "insert into ct_unit(unit_type_uuid,unit_uuid,name,base_flag,multiplier) values('$unit_type_id','$unit_id','$base_unit_name','1',0)";
	$res = $db->Execute($query);
	if ($res == true) {
		$base_unit_saved_ok = true;
	}

	if ($unit_type_saved_ok == true && $base_unit_saved_ok == true) {
?>
    <div id="result_msg">
    <?php echo $unit_type_name." was succesfully saved in the Database.";?>
    </div>
	<?php


	}
	elseif ($unit_type_saved_ok == true && $base_unit_saved_ok == false) {
		$q = "delete from ct_unit_type where unit_type_uuid = '$unit_type_id'";
		$res = $db->Execute($q);
?>
    <div id="result_msg">
    <?php print "Your Operation aborted. <b>ct_unit</b> table is not found in the Database";?>
    </div>
	<?php


	}
	elseif ($unit_type_saved_ok == false && $base_unit_saved_ok == true) {
		$q = "delete from ct_unit where unit_type_uuid = '$unit_type_id'";
		$res = $db->Execute($q);
?>
    <div id="result_msg">
    <?php print "Your Operation aborted. <b>ct_unit_type</b> table is not found in the Database";?>
    </div>
	<?php


	} else {
?>
    <div id="result_msg">
    <?php print "Your Operation aborted. <b>ct_unit_type</b> and <b>ct_unit</b> tables are not found in the Database";?>
    </div>
	<?php


	}

}

function _shn_service_search_keyword_result() {
	global $global;
	$db = $global["db"];

	print "Click on the parent catalogue that you need to add sub catalogue or Item under it.<br> ";

	$search_keyword = $name = trim($_POST['search_keyword']);
	$type = trim($_POST['type']);
?>
<br>
<div id="result">
<table>
    <thead>
        <td><strong><?=_t("Name")?></strong></td>
        <td><strong><?=_t("Description")?></strong></td>
        <td><strong><?=_t("Item/Catalogue")?></strong></td>
	<td><strong><?=_t("Keyword")?></strong></td>
    </thead>
    <TBODY>
    <?php


	$first_3_letters = substr($search_keyword, 0, 2);
	$query = "select * from ct_catalogue where keyword like '$first_3_letters%' and final_flag!='1' ";
	$res = $db->Execute($query);

	while (!$res == NULL && !$res->EOF) {
		$name = $res->fields["name"];
		$description = $res->fields["description"];
		$cat_id = $res->fields["ct_uuid"];
		$final_flag = $res->fields["final_flag"];
		$keyword = $res->fields["keyword"];
?>
    <tr>
        <td><a href="index.php?mod=cs&act=search_keyword_select_submit&id=<?php echo $cat_id ?>&type=<?php echo $type ?>"><?php print $name ;?></a></td>
        <td><?php print $description ;?></td>
        <?php if($final_flag=='0') { ?>
            <td><?php print "Catalogue" ; ?></td>
        <?php } else { ?>
            <td><?php print "Item" ; ?></td>
        <?php } ?>
	<td><?php print $keyword ;?></td>
    </tr>
    <?php


		$res->MoveNext();
	} //end of while loop
?>
    </TBODY>    
</table>
</div>
<?php


}

/**
 * This function validates the values entered in add unit form.
 *This function is called by shn_service_addunit_form_submit() in main.inc
 * @access private
 * @return boolean
 */

function _shn_service_validate_unitform() {
	$error_flag = false;
	clean_errors();

	//this checks whether name entered in the add unit form
	if (trim($_POST['unit_name']) == null) {
		add_error(_t("Please Enter the Unit Name"));
		$error_flag = true;
	}

	if (trim($_POST['multiplier']) == null) {
		add_error(_t("Please Enter the Multiplier"));
		$error_flag = true;
	}

	return $error_flag;
}

function _shn_service_validate_subcatform() {
	$error_flag = false;
	clean_errors();

	//this checks whether name entered in the add sub category form
	if (trim($_POST['sub_cat_name']) == null) {
		add_error(_t("Please Enter the Sub Category Name"));
		$error_flag = true;
	}

	return $error_flag;
}

function _shn_service_validate_additem_form() {
	$error_flag = false;
	clean_errors();

	//this checks whether name entered in the add Item form
	if (trim($_POST['itemname']) == null) {
		add_error(_t("Please Enter the Item Name"));
		$error_flag = true;
	}

	if (trim($_POST['measurement_type']) == null || trim($_POST['measurement_type']) == 'none') {
		add_error(_t("Please Select the Unit Type"));
		$error_flag = true;
	}

	if (trim($_POST['unit_select']) == null) {
		add_error(_t("Please Select Unit/Units"));
		$error_flag = true;
	}

	return $error_flag;
}

function _shn_service_validate_unit_type_form() {
	$error_flag = false;
	clean_errors();

	//this checks whether name entered in the add Item form
	if (trim($_POST['unit_type_name']) == null) {
		add_error(_t("Please Enter the Unit Type Name"));
		$error_flag = true;
	}

	if (trim($_POST['base_unit_name']) == null) {
		add_error(_t("Please Enter the Base Unit Name"));
		$error_flag = true;
	}

	return $error_flag;
}
?>


<script type="text/javascript">
    function changeform()
    {
    //document.select_unit_type_form.submit();
    var x=document.select_unit_type_form.unit_type.options[document.select_unit_type_form.unit_type.selectedIndex].value;
    if(x!='none')
        {
        document.select_unit_type_form.submit();
        }
    }
</script>
<?php

?>
<script type="text/javascript">
    var url = "index.php?"; 
     var http;
        
    function getHTTPObject() 
    {
        var xmlhttp;
        
        //conditional compliation
        /*@cc_on
        @if (@_jscript_version >= 5)
            try {
                xmlhttp = new ActiveXObject("Msxml2.XMLHTTP");
            } catch (e) {
                try {
                    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
                } catch (E) {
                    xmlhttp = false;
                }
            }
        @else
            xmlhttp = false;
        @end @*/

        if (!xmlhttp && typeof XMLHttpRequest != 'undefined') {
            try {
                xmlhttp = new XMLHttpRequest();

            } catch (e) {
            xmlhttp = false;
            }
        }

    return xmlhttp;
    }

function handleHttpResponse(){
        if (http.readyState == 4) 
    { // Split the comma delimited response into an array  
                results = http.responseText.split(",");
                if (results[0]!="null")
            {                
                var x=document.getElementsByName('unit_select[]');

                    for (i=0; i<=x[0].options.length+1; i++)
                    {
                            x[0].options[0]=null;
                            }

                j=0;
                for (i=1; i<results.length-1; i=i+2, j++)
                    {
                    //alert(results[i]);
                         opt = document.createElement("option") ;
                          opt.value = results[i] ;
                          opt.text = results[i+1].replace(/[^A-Za-z]$/,"");
                          x[0].options[j] = opt;
                            }
                    }
        } 
    }

    function change_units(selection){
    
        http = getHTTPObject();

        var url2=url + "act=unit_cat&mod=xst&stream=text&cat="+selection;
          http.open("GET", url2, true); 
        http.onreadystatechange = function(){}; 
        http.onreadystatechange = handleHttpResponse; 
        http.send(null);
    }
</script>
<?php

?>

