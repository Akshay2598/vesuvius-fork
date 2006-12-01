<?php
/* $Id: [sahana_home]/mod/vm/admin.inc,v 1.0 2006/07/25  */
/**
*
* Admin controller of the Organization Registry (PHP version 4 and 5)
*
* <p>LICENSE: This source file is subject to LGPL license
* that is available through the world-wide-web at the following URI:
* http://www.gnu.org/copyleft/lesser.html</p>
*
* @package    Trinity_College_VM_Module
* @author     Ravindra De Silva <ravindra@opensource.lk><ravidesilva@iee.org>
* @author     Jonathan Damon <jonathan.damon@trincoll.edu>
* @copyright  Copyright {@link http://www.opensource.lk Lanka Software Foundation} 2006
*/

/** Contains library functions for creating forms. */
include_once($global['approot'].'/inc/lib_form.inc');
/** Contains library functions for VM and VR forms. */
include_once($global['approot'].'/mod/vm/lib_vm.inc');
//include_once "admin_forms.inc";

function _shn_vm_adm_sub_menu(){
?>
<div id="submenu_v">
<a href="index.php?mod=vm&act=adm_vol_assign">Assign Volunteers</a> 
<a href="index.php?mod=vm&act=adm_vol_display">Display Volunteers</a>
<a href="index.php?mod=vm&act=adm_proj_add">Add Project</a>
<a href="index.php?mod=vm&act=adm_proj_display">View Projects</a>
<a href="index.php?mod=vm&act=adm_proj_report">Work Summaries</a>
<a href="index.php?mod=vm&act=adm_type_form">Skill Set Modifications</a>
</div>

<br>
<?php
}
function shn_vm_adm_default()
{
   _shn_vm_adm_sub_menu();
?>
    <p><b> Welcome to the VM admin page </b></p>
    <p> Use the Above Navigation to Administer VM</p>
<?php
}

function shn_vm_adm_vol_assign()
{
   _shn_vm_adm_sub_menu();
   include_once ("vol_assign.inc"); 
    _shn_vm_vol_assign($error);
}

function shn_vm_adm_vol_display()
{
   _shn_vm_adm_sub_menu();
   include_once("vol_display.inc");
   shn_vm_vol_display();
}

function shn_vm_adm_proj_add()
{
   _shn_vm_adm_sub_menu();
    include_once("proj_add.inc");
    _shn_vm_regform_proj_add();
}

function shn_vm_adm_proj_display()
{
   _shn_vm_adm_sub_menu();
    include_once("proj_display.inc");
    _shn_vm_proj_display();
}

function shn_vm_adm_proj_report()
{
   _shn_vm_adm_sub_menu();
    include_once("proj_report.inc");
    _shn_vm_proj_report();
}

function shn_vm_adm_type_form()
{
   _shn_vm_adm_sub_menu();
?>
<h2><?=_("Skill Types")?></h2>
<?php
    if($error==true)
        display_errors();
?>
<div id="formcontainer">
<?php
    shn_form_fopen("adm_type_cr");
    _shn_vm_admin_javascript("opt_skill_type");
    shn_form_fsopen("Add New Type Information");
    shn_form_text(_("Skill Description : "),'type','size="50"',null); 
    shn_form_text(_("Abbrevation [3 letter unique abbr. to store in the database] : "),'type_abbr','size="50"',null); 
    shn_form_hidden(array("added"=>'0'));
    shn_form_hidden(array("removed"=>'0'));
    shn_form_button(_("Add"),"onClick='add_types()'");
    shn_form_fsclose();
 ?>
</center>
<?php
    shn_form_fsopen("Remove Types");
    _shn_vm_display_skill_types($error,true);
     shn_form_button(_("Remove"),"onClick='remove_types()'");
    shn_form_fsclose();
 ?>
</center>
<br />
<center>
<?php
   shn_form_submit(_("Save"))
?>
</center>
<br />
<?php
    //close the form
    shn_form_fclose();
?>				     
</div>
<?php
    // end of form
}//shn_vm_adm_type_form()

function shn_vm_adm_type_cr()
{
    global $global;
    $db=$global['db'];
    $add = explode(":", $_POST{"added"});
    $remove = explode(":", $_POST{"removed"});
    for($i=1;$i<count($add);$i++){
        $temp = explode("|", $add[$i]);
        $q="insert into field_options(field_name,option_code,option_description) values('opt_skill_type','{$temp[0]}','{$temp[1]}')";
        $res=$db->Execute($q);
    }
    for($i=1;$i<count($remove);$i++){
        $temp = explode("|", $remove[$i]);
        $q="delete from field_options where field_name='opt_skill_type' and option_code='".$temp[0]."'";
        $res=$db->Execute($q);
    }
    shn_vm_adm_type_form();
}

function shn_vm_adm_acl_install()
{
    global $global;
    $db=$global["db"];
    $q="select value from config where module_id='vm' and confkey='acl_base'";
    $res_acl=$db->Execute($q);
    if(!$res_acl->EOF && $res_acl->fields[0]=='installed'){
        $msg="ACL Base for Volunteer Management Module is already installed";
    }
    include_once $global['approot']. 'inc/lib_security/acl_api.inc';
    include_once $global['approot'].'inc/lib_security/acl.inc';
    include_once $global['approot'].'inc/lib_security/authenticate.inc';
    $acl=new SahanaACL(NULL);

 /** start of or specifc ACL entries
 **/
    // add a module named "or"
    $res=shn_acl_add_module("vm","volunteer management");
    
    
    /** action groups **/
    // add an action group named "deny_admin" under the module "or"
    $res=shn_acl_add_action_group("vm","deny_admin","Administrative Action Group");
    $res=shn_acl_add_action("vm","deny_admin","shn_vm_adm_vol_assign","Assign Volunteers to Projects");
    $res=shn_acl_add_action("vm","deny_admin","shn_vm_adm_vol_display","Display all Volunteers");
    $res=shn_acl_add_action("vm","deny_admin","shn_vm_adm_proj_add","Add a new Project");
    $res=shn_acl_add_action("vm","deny_admin","shn_vm_adm_proj_display","Display all Projects");
    $res=shn_acl_add_action("vm","deny_admin","shn_vm_adm_proj_report","Work Summary Reports");
    $res=shn_acl_add_action("vm","deny_admin","shn_vm_adm_type_form","Edit Skill Types");
     //deny permission for 'deny_admin' action group with in 'or' to 'guest' role
    $res=shn_acl_add_perms_action_group_role('guest','vm','deny_admin');
    $res=shn_acl_add_perms_action_group_role('user','vm','deny_admin');
    
    // add an action group named "deny_user" under the module "or"
    $res=shn_acl_add_action_group("vm","deny_user","deny user group");
    //add an action name 'shn_or_reg_org"  under above action groups
    $res=shn_acl_add_action("vm","deny_user","shn_vm_vol_assign","Assign Volunteers to Projects");
    $res=shn_acl_add_action("vm","deny_user","shn_vm_volunteer_detail","Detailed info on volunteers");
    $res=shn_acl_add_action("vm","deny_user","shn_vm_proj_detail","Detailed info on projects");
    $res=shn_acl_add_action("vm","deny_user","shn_vm_vol_display","Display all Volunteers");
    $res=shn_acl_add_action("vm","deny_user","shn_vm_proj_add","Add a new Project");
    $res=shn_acl_add_action("vm","deny_user","shn_vm_proj_report","Work Summary Reports"); 

	$res=shn_acl_add_perms_action_group_role('guest','vm','deny_user');

    if($res_acl->EOF)
	 $q="insert into config values('vm','acl_base','installed')";
    else
	 $q="update config set value='installed' where module_id='vm' and confkey='acl_base'";
    $res=$db->Execute($q);
    $msg="ACL Base for Volunteer Management Module was succesfully installed";

?>
    <div id="result_msg">
       <?php echo $msg;?>
    </div>
    </br>
<?php
}



?>