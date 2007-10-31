
-- GROUP TYPES
INSERT INTO field_options VALUES('opt_group_type','fam','family');
INSERT INTO field_options VALUES('opt_group_type','com','company');
INSERT INTO field_options VALUES('opt_group_type','soc','society');
INSERT INTO field_options VALUES('opt_group_type','tor','tourists');
INSERT INTO field_options VALUES('opt_group_type','oth','other');
INSERT INTO field_options VALUES('opt_group_type','===','==Select Option==');
-- IDENTITY CARD / PASSPORT TYPES
INSERT INTO field_options VALUES('opt_id_type','nic','National Identity Card');
INSERT INTO field_options VALUES('opt_id_type','pas','Passport');
INSERT INTO field_options VALUES('opt_id_type','dln','Driving License Number');
INSERT INTO field_options VALUES('opt_id_type','oth','Other');

-- PERSON STATUS VALUES
INSERT INTO field_options VALUES ('opt_status','ali','Alive & Well');
INSERT INTO field_options VALUES ('opt_status','mis','Missing');
INSERT INTO field_options VALUES ('opt_status','inj','Injured');
INSERT INTO field_options VALUES ('opt_status','dec','Deceased');


-- PERSON GENDER 
-- INSERT INTO field_options VALUES ('opt_gender','unk','Unknown');
INSERT INTO field_options VALUES ('opt_gender','mal','Male');
INSERT INTO field_options VALUES ('opt_gender','fml','Female');

-- PERSON RELATIONSHIPS
INSERT INTO field_options VALUES('opt_relationship_type','fat','Father');
INSERT INTO field_options VALUES('opt_relationship_type','mot','Mother');
INSERT INTO field_options VALUES('opt_relationship_type','bro','Brother');
INSERT INTO field_options VALUES('opt_relationship_type','sis','Sister');
INSERT INTO field_options VALUES('opt_relationship_type','gft','GrandFather');
INSERT INTO field_options VALUES('opt_relationship_type','gmt','GrandMother');
INSERT INTO field_options VALUES('opt_relationship_type','gfpat','GrandFatherPaternal');
INSERT INTO field_options VALUES('opt_relationship_type','gfmat','GrandFatherMaternal');
INSERT INTO field_options VALUES('opt_relationship_type','gmpat','GrandMotherPaternal');
INSERT INTO field_options VALUES('opt_relationship_type','gmmat','GrandMotherMaternal');
INSERT INTO field_options VALUES('opt_relationship_type','fnd','Friend');
INSERT INTO field_options VALUES('opt_relationship_type','oth','Other');



-- PERSON CONTACT TYPES
INSERT INTO field_options VALUES ('opt_contact_type','home','Home(permanent address)');
INSERT INTO field_options VALUES ('opt_contact_type','name','Contact Person');
INSERT INTO field_options VALUES ('opt_contact_type','pmob','Personal Mobile');
INSERT INTO field_options VALUES ('opt_contact_type','curr','Current Phone');
INSERT INTO field_options VALUES ('opt_contact_type','cmob','Current Mobile');
INSERT INTO field_options VALUES ('opt_contact_type','emai','Email address');
INSERT INTO field_options VALUES ('opt_contact_type','fax','Fax Number');
INSERT INTO field_options VALUES ('opt_contact_type','web','Website');
INSERT INTO field_options VALUES ('opt_contact_type','inst','Instant Messenger');

-- PERSON LOCATION TYPES 
INSERT INTO field_options VALUES ('opt_person_loc_type','hom','Permanent home address)');
INSERT INTO field_options VALUES ('opt_person_loc_type','imp','Impact location');
INSERT INTO field_options VALUES ('opt_person_loc_type','cur','Current location');

-- AGE GROUP VALUES
INSERT INTO field_options VALUES ('opt_age_group','unk','Unknown');
INSERT INTO field_options VALUES ('opt_age_group','inf','Infant (0-1)');
INSERT INTO field_options VALUES ('opt_age_group','chi','Child (1-15)');
INSERT INTO field_options VALUES ('opt_age_group','you','Young Adult (16-21)');
INSERT INTO field_options VALUES ('opt_age_group','adu','Adult (22-50)');
INSERT INTO field_options VALUES ('opt_age_group','sen','Senior Citizen (50+)');

-- COUNTRY VALUES
INSERT INTO field_options VALUES ('opt_country','uk','United Kingdom');
INSERT INTO field_options VALUES ('opt_country','lanka','Sri Lanka');

-- RACE VALUES 
INSERT INTO field_options VALUES ('opt_race','unk','Unknown');
INSERT INTO field_options VALUES ('opt_race','filip','Filipino');
INSERT INTO field_options VALUES ('opt_race','other','Other');

-- RELIGION VALUES 
INSERT INTO field_options VALUES ('opt_religion','unk','Unknown');
INSERT INTO field_options VALUES ('opt_religion','bud','Buddhist');
INSERT INTO field_options VALUES ('opt_religion','chr','Christian');
INSERT INTO field_options VALUES ('opt_religion','mus','Muslim');
INSERT INTO field_options VALUES ('opt_religion','oth','Other');

-- MARITIAL STATUS VALUES 
INSERT INTO field_options VALUES ('opt_marital_status','unk','Unknown');
INSERT INTO field_options VALUES ('opt_marital_status','sin','Single');
INSERT INTO field_options VALUES ('opt_marital_status','mar','Married');
INSERT INTO field_options VALUES ('opt_marital_status','div','Divorced');

-- BLOOD TYPE VALUES 
INSERT INTO field_options VALUES ('opt_blood_type','unk','Unknown');
INSERT INTO field_options VALUES ('opt_blood_type','ab','AB');
INSERT INTO field_options VALUES ('opt_blood_type','a+','A+');
INSERT INTO field_options VALUES ('opt_blood_type','o','O');

-- EYE COLOR VALUES
INSERT INTO field_options VALUES ('opt_eye_color','unk','Unknown');
INSERT INTO field_options VALUES ('opt_eye_color','bla','Black');
INSERT INTO field_options VALUES ('opt_eye_color','bro','Light Brown');
INSERT INTO field_options VALUES ('opt_eye_color','blu','Blue');
INSERT INTO field_options VALUES ('opt_eye_color','oth','Other');

-- SKIN COLOR VALUES
INSERT INTO field_options VALUES ('opt_skin_color','unk','Unknown');
INSERT INTO field_options VALUES ('opt_skin_color','bla','Black');
INSERT INTO field_options VALUES ('opt_skin_color','bro','Dark Brown');
INSERT INTO field_options VALUES ('opt_skin_color','fai','Fair');
INSERT INTO field_options VALUES ('opt_skin_color','whi','White');
INSERT INTO field_options VALUES ('opt_skin_color','oth','Other');

-- HAIR COLOR VALUES
INSERT INTO field_options VALUES ('opt_hair_color','unk','Unknown');
INSERT INTO field_options VALUES ('opt_hair_color','bla','Black');
INSERT INTO field_options VALUES ('opt_hair_color','bro','Brown');
INSERT INTO field_options VALUES ('opt_hair_color','red','Red');
INSERT INTO field_options VALUES ('opt_hair_color','blo','Blond');
INSERT INTO field_options VALUES ('opt_hair_color','oth','Other');

-- CAMP TYPE VALUES 
INSERT INTO field_options VALUES ('opt_camp_type','ngo','NGO Run Camp');
INSERT INTO field_options VALUES ('opt_camp_type','tmp','Temporary Shelter');
INSERT INTO field_options VALUES ('opt_camp_type','gov','Government Evacuation Center');

-- CAMP SERVICES 
INSERT INTO field_options VALUES ('opt_camp_service','adm','Administrative Facilities');
INSERT INTO field_options VALUES ('opt_camp_service','snt','Sanitation Facilities');
INSERT INTO field_options VALUES ('opt_camp_service','wat','Water Facilities');
INSERT INTO field_options VALUES ('opt_camp_service','mdc','Medical Facilities');

-- ORGANIZATION TYPES 
INSERT INTO field_options VALUES('opt_org_type','gov','Government');
INSERT INTO field_options VALUES('opt_org_type','priv','Private');
INSERT INTO field_options VALUES('opt_org_type','ngo','NGO');
INSERT INTO field_options VALUES('opt_org_type','ingo','International NGO');
INSERT INTO field_options VALUES('opt_org_type','mngo','Multinational NGO');

-- ORGANIZATION TYPES 
INSERT INTO field_options VALUES('opt_org_sub_type','dep','Department');
INSERT INTO field_options VALUES('opt_org_sub_type','subs','Subsidiary');
INSERT INTO field_options VALUES('opt_org_sub_type','bra','Branch');

-- ORGANIZATION SECTOR VALUES
INSERT INTO field_options VALUES('opt_sector_type','sup','Supplier of Goods');
INSERT INTO field_options VALUES('opt_sector_type','comm','Communications');
INSERT INTO field_options VALUES('opt_sector_type','med','Medical');
INSERT INTO field_options VALUES('opt_sector_type','rehab','Rehabilitation');
INSERT INTO field_options VALUES('opt_sector_type','edu','Education');


-- LOCATION TYPE VALUES
INSERT INTO field_options VALUES ('opt_location_type','1','Country');
INSERT INTO field_options VALUES ('opt_location_type','2','State');
INSERT INTO field_options VALUES ('opt_location_type','3','City');

-- CATALOGUE MAX_DEPTH VALUE
INSERT INTO field_options VALUES ('opt_cs_depth','6','depth');
INSERT INTO field_options VALUES ('opt_cs_page_record','30','number of page records');

-- REPORT AND CHART UPDATE FREQUENCY VALUES
INSERT INTO field_options VALUES ('opt_rs_rep_freq','30','the frequency of report update');
INSERT INTO field_options VALUES ('opt_rs_cht_freq','30','the frequency of chart update');

-- INSERT MODULE VALUES
-- INSERT INTO modules VALUES ('cr', '0.2', TRUE);
-- INSERT INTO modules VALUES ('or', '0.2', TRUE);
-- INSERT INTO modules VALUES ('admin', '0.2', TRUE);
-- INSERT INTO modules VALUES ('gis', '0.2', TRUE);

-- INSERT CONFIG VALUES
INSERT INTO config (module_id,confkey,value) VALUES ( 'cr', 'division_type', '2');

-- INSERT DEFAULT DATA CLASSIFICATION LEVELS
INSERT INTO sys_data_classifications VALUES ( 1, 'Person Sensitive');
INSERT INTO sys_data_classifications VALUES ( 2, 'Organization Sensitive');
INSERT INTO sys_data_classifications VALUES ( 3, 'Legally Sensitive');
INSERT INTO sys_data_classifications VALUES ( 4, 'National Security Sensitive');
INSERT INTO sys_data_classifications VALUES ( 5, 'Socially Sensitive');
INSERT INTO sys_data_classifications VALUES ( 6, 'System Sensitive');
INSERT INTO sys_data_classifications VALUES ( 7, 'Not Sensitive');
INSERT INTO sys_data_classifications VALUES ( 8, 'Unclassified');

-- INSERT DEFAULT SYS USER GROUPS
INSERT INTO sys_user_groups VALUES ( 1, 'Administrator (Admin)');
INSERT INTO sys_user_groups VALUES ( 2, 'Registered User');
INSERT INTO sys_user_groups VALUES ( 3, 'Anonymous User');
INSERT INTO sys_user_groups VALUES ( 4, 'Super User (Head of Operations)');
INSERT INTO sys_user_groups VALUES ( 5, 'Organization Admin');
INSERT INTO sys_user_groups VALUES ( 6, 'Volunteer Coordinator');
INSERT INTO sys_user_groups VALUES ( 7, 'Camp Admin');

-- INSERT DEFAULT SYS USER GROUP TO DATA CLASSIFICATION MAPPINGS
-- admin role
-- admin(1) can create(8),read(4),update(2),delete(1) (totaling 15) System sensitive(6) data  
INSERT INTO sys_group_to_data_classification VALUES ( 1, 1,"-r--");
-- no perms
INSERT INTO sys_group_to_data_classification VALUES ( 1, 2,"-r--");
-- read only
INSERT INTO sys_group_to_data_classification VALUES ( 1, 3,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 1, 4,"----");
INSERT INTO sys_group_to_data_classification VALUES ( 1, 5,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 1, 6,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 1, 7,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 1, 8,"crud");


INSERT INTO sys_group_to_data_classification VALUES ( 2, 1,"-r--");
INSERT INTO sys_group_to_data_classification VALUES ( 2, 2,"-r--");
INSERT INTO sys_group_to_data_classification VALUES ( 2, 3,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 2, 4,"----");
INSERT INTO sys_group_to_data_classification VALUES ( 2, 5,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 2, 6,"-r--");
INSERT INTO sys_group_to_data_classification VALUES ( 2, 7,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 2, 8,"crud");


INSERT INTO sys_group_to_data_classification VALUES ( 3, 1,"----");
INSERT INTO sys_group_to_data_classification VALUES ( 3, 2,"----");
INSERT INTO sys_group_to_data_classification VALUES ( 3, 3,"-r--");
INSERT INTO sys_group_to_data_classification VALUES ( 3, 4,"----");
INSERT INTO sys_group_to_data_classification VALUES ( 3, 5,"-r--");
INSERT INTO sys_group_to_data_classification VALUES ( 3, 6,"----");
INSERT INTO sys_group_to_data_classification VALUES ( 3, 7,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 3, 8,"crud");

INSERT INTO sys_group_to_data_classification VALUES ( 4, 1,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 4, 2,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 4, 3,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 4, 4,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 4, 5,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 4, 6,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 4, 7,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 4, 8,"crud");

INSERT INTO sys_group_to_data_classification VALUES ( 5, 1,"----");
-- no perms
INSERT INTO sys_group_to_data_classification VALUES ( 5, 2,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 5, 3,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 5, 4,"----");
INSERT INTO sys_group_to_data_classification VALUES ( 5, 5,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 5, 6,"-r--");
INSERT INTO sys_group_to_data_classification VALUES ( 5, 7,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 5, 8,"crud");

INSERT INTO sys_group_to_data_classification VALUES ( 6, 1,"----");
-- no perms
INSERT INTO sys_group_to_data_classification VALUES ( 6, 2,"-r--");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 3,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 4,"----");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 5,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 6,"-r--");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 7,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 8,"crud");

INSERT INTO sys_group_to_data_classification VALUES ( 6, 1,"----");
-- no perms
INSERT INTO sys_group_to_data_classification VALUES ( 6, 2,"-r--");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 3,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 4,"----");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 5,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 6,"-r--");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 7,"crud");
INSERT INTO sys_group_to_data_classification VALUES ( 6, 8,"crud");

-- INSERT DEFAULT TABLE FIELD TO DATA CLASSIFICATION MAPPINGS

-- TABLE NAMES ARE SORTED IN ALPHEBATICAL ORDER

-- adodb_logsql

-- alt_logins

-- audit
INSERT INTO sys_tablefields_to_data_classification VALUES ( "audit", 6);

-- camp_admin

-- camp_general

-- camp_reg
INSERT INTO sys_tablefields_to_data_classification VALUES ( "camp_reg", 5);

-- camp_services
INSERT INTO sys_tablefields_to_data_classification VALUES ( "camp_services", 7);

-- chronology
INSERT INTO sys_tablefields_to_data_classification VALUES ( "chronology", 6);

-- config
INSERT INTO sys_tablefields_to_data_classification VALUES ( "config", 6);

-- contact
INSERT INTO sys_tablefields_to_data_classification VALUES ( "contact", 5);

-- ct_cat_unit
INSERT INTO sys_tablefields_to_data_classification VALUES ( "ct_cat_unit", 7);

-- ct_catalogue
INSERT INTO sys_tablefields_to_data_classification VALUES ( "ct_catalogue", 6);

-- ct_unit
INSERT INTO sys_tablefields_to_data_classification VALUES ( "ct_unit", 7);

-- ct_unit_type
INSERT INTO sys_tablefields_to_data_classification VALUES ( "ct_unit_type", 7);

-- devel_logsql

-- field_options
INSERT INTO sys_tablefields_to_data_classification VALUES ( "field_options", 6);

-- gis_feature

-- gis_location

-- gis_wiki

-- group_details
INSERT INTO sys_tablefields_to_data_classification VALUES ( "group_details", 1);

-- hr_assign_contractor_to_site_table

-- hr_assign_site_to_contractor_table

-- hr_contractor_table

-- hr_damaged_house_basic_details_table

-- hr_damaged_house_location_details_table

-- hr_family_head_details_table

-- hr_site_allocated_organization_table

-- hr_site_house_details_table

-- hr_site_infrastructure_details_table

-- hr_site_location_details_table

-- hr_site_main_coordinator_details_table

-- hr_site_name_and_uid_table

-- identity_to_person
INSERT INTO sys_tablefields_to_data_classification VALUES ( "identity_to_person", 1);

-- image
INSERT INTO sys_tablefields_to_data_classification VALUES ( "image", 6);

-- ims_alternate
INSERT INTO sys_tablefields_to_data_classification VALUES ( "ims_alternate", 6);

-- ims_inventory_records
INSERT INTO sys_tablefields_to_data_classification VALUES ( "ims_inventory_records", 6);

-- ims_item_records
INSERT INTO sys_tablefields_to_data_classification VALUES ( "ims_item_records", 6);

-- ims_optimization
INSERT INTO sys_tablefields_to_data_classification VALUES ( "ims_optimization", 7);

-- ims_relation
INSERT INTO sys_tablefields_to_data_classification VALUES ( "ims_relation", 6);

-- ims_reorder_level
INSERT INTO sys_tablefields_to_data_classification VALUES ( "ims_reorder_level", 6);

-- ims_transfer_item
INSERT INTO sys_tablefields_to_data_classification VALUES ( "ims_transfer_item", 6);

-- incident
INSERT INTO sys_tablefields_to_data_classification VALUES ( "incident", 6);

-- landmark_location

-- lc_fields
INSERT INTO sys_tablefields_to_data_classification VALUES ( "lc_fields", 6);

-- lc_tmp_po
INSERT INTO sys_tablefields_to_data_classification VALUES ( "lc_tmp_po", 6);

-- location
INSERT INTO sys_tablefields_to_data_classification VALUES ( "location", 6);

-- location_details
INSERT INTO sys_tablefields_to_data_classification VALUES ( "location_details", 5);

-- messaging_group

-- old_passwords

-- org_main
INSERT INTO sys_tablefields_to_data_classification VALUES ( "org_main", 2);

-- password_event_log

-- person

-- person_deceased
INSERT INTO sys_tablefields_to_data_classification VALUES ( "person_deceased", 1);

-- person_details
INSERT INTO sys_tablefields_to_data_classification VALUES ( "person_details", 1);

-- person_missing
INSERT INTO sys_tablefields_to_data_classification VALUES ( "person_missing", 1);

-- person_physical
INSERT INTO sys_tablefields_to_data_classification VALUES ( "person_physical", 1);

-- person_status
INSERT INTO sys_tablefields_to_data_classification VALUES ( "person_status", 1);

-- person_to_pgroup
INSERT INTO sys_tablefields_to_data_classification VALUES ( "person_to_pgroup", 1);

-- person_to_report
INSERT INTO sys_tablefields_to_data_classification VALUES ( "person_to_report", 1);

-- person_uuid
INSERT INTO sys_tablefields_to_data_classification VALUES ( "person_uuid", 1);

-- pgroup
INSERT INTO sys_tablefields_to_data_classification VALUES ( "pgroup", 1);

-- phonetic_word

-- report_files

-- report_keywords

-- resource_to_incident
INSERT INTO sys_tablefields_to_data_classification VALUES ( "resource_to_incident", 6);

-- rms_fulfil

-- rms_pledge

-- rms_plg_item

-- rms_priority

-- rms_req_item

-- rms_request

-- rms_status

-- rms_tmp_sch

-- sector
INSERT INTO sys_tablefields_to_data_classification VALUES ( "sector", 2);

-- sessions
INSERT INTO sys_tablefields_to_data_classification VALUES ( "sessions", 6);

-- sync_instance
INSERT INTO sys_tablefields_to_data_classification VALUES ( "sync_instance", 6);

-- sys_data_classifications
INSERT INTO sys_tablefields_to_data_classification VALUES ( "sys_data_classifications", 6);

-- sys_group_to_data_classification
INSERT INTO sys_tablefields_to_data_classification VALUES ( "sys_group_to_data_classification", 6);

-- sys_group_to_module

-- sys_tablefields_to_data_classification
INSERT INTO sys_tablefields_to_data_classification VALUES ( "sys_tablefields_to_data_classification", 6);

-- sys_user_groups
INSERT INTO sys_tablefields_to_data_classification VALUES ( "sys_user_groups", 6);

-- sys_user_to_group
INSERT INTO sys_tablefields_to_data_classification VALUES ( "sys_user_to_group", 6);

-- unit

-- unit_type

-- user_preference

-- users
INSERT INTO sys_tablefields_to_data_classification VALUES ( "users", 6);

-- vm_access_classification_to_request

-- vm_access_constraint

-- vm_access_constraint_to_request

-- vm_access_request

-- vm_courier

-- vm_hours

-- vm_image

-- vm_mailbox

-- vm_message

-- vm_position

-- vm_position_active

-- vm_position_full

-- vm_positiontype

-- vm_projects

-- vm_projects_active

-- vm_vol_active

-- vm_vol_details

-- vm_vol_position

-- vm_vol_skills

-- ws_keys

