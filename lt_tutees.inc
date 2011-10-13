

<!--Tutee Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1">Tutees</h1>
<hr/>
<h3 class="h3body">2008/2009</h3><p class="pararight">Tutee Detail</p>
<table width="1020px" cellspacing="0" summary="Modulemark">
  
  
  <tr>
  <th scope="col" abbr="Name" class="nobg">Name</th>
  <th scope="col" abbr="CW1">ID</th>
  <th scope="col" abbr="CW2">MEF Status</th>
  <th scope="col" abbr="EXAM">Module Enrollment</th>
  </tr>
  <?php
  $lecturer_id = $_SESSION['valid_user'];
  $tutees= get_tutees($lecturer_id);
  
  foreach($tutees as $tut)
  {
  if(mef_status($tut,semester())==true)
  $status ='Submitted';
  else
  $status = 'Not Submitted';
  echo'
  
  <tr>
    <th scope="row" class="spec">'.get_name($tut,'student').'</th>
    <td>'.get_rollno($tut).'</td>
    <td>'.$status.'</td>
    <td>';
    $modules_taken = modules_taken_sem($tut,semester(),year_studying($tut));
    for($i=0;$i<count($modules_taken);$i++)
    {
    	echo $modules_taken[$i];
    	if($i!=count($modules_taken)-1)
    	echo ',';
		    
    }
	
	
	echo'</td>
  </tr>
  
  
  ';
  
  }
  ?>
</table><br><br><br>
<!--Please make below auto calculated-->
</div>
<!--end Module Detail -->