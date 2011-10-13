<?php

require_once('tcpdf/config/lang/eng.php');
require_once('tcpdf/tcpdf.php');



// Extend the TCPDF class to create custom Header and Footer
class MYPDF extends TCPDF {
	
	 var $module_code;
	
    //Page header
    public function set_module_code($modulecode)
    {
    	   $this->module_code = $modulecode;
    	  
    }
    
    public function Header() {
        // Logo
        $this->Image(K_PATH_IMAGES.'logo.jpg', 10, 8, 35);
        // Set font
        $this->SetFont('helvetica', 'B', 20);
        // Move to the right
        $this->Cell(80);
        // Title
        $title = 'Module report-'.$this->module_code;
        $this->Cell(30, 10, $title, 0, 0, 'C');
        // Line break
        $this->Ln(20);
    }
    
    // Page footer
    public function Footer() {
        // Position at 1.5 cm from bottom
        $this->SetY(-15);
        // Set font
        $this->SetFont('helvetica', 'I', 8);
        // Page number
        $this->Cell(0, 10, 'Page '.$this->getAliasNumPage().'/'.$this->getAliasNbPages(), 0, 0, 'C');
    }
}












$pdf = new MYPDF(PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT, true, 'UTF-8', false); 

$pdf->set_module_code($module_code);
// set default header data
//$pdf->SetHeaderData(PDF_HEADER_LOGO, PDF_HEADER_LOGO_WIDTH, PDF_HEADER_TITLE, PDF_HEADER_STRING);

// set header and footer fonts
$pdf->setHeaderFont(Array(PDF_FONT_NAME_MAIN, '', PDF_FONT_SIZE_MAIN));
$pdf->setFooterFont(Array(PDF_FONT_NAME_DATA, '', PDF_FONT_SIZE_DATA));

//set margins
$pdf->SetMargins(PDF_MARGIN_LEFT, PDF_MARGIN_TOP, PDF_MARGIN_RIGHT);
$pdf->SetHeaderMargin(PDF_MARGIN_HEADER);
$pdf->SetFooterMargin(PDF_MARGIN_FOOTER);

//set auto page breaks
$pdf->SetAutoPageBreak(TRUE, PDF_MARGIN_BOTTOM);

//set image scale factor
$pdf->setImageScale(PDF_IMAGE_SCALE_RATIO); 

//set some language-dependent strings
$pdf->setLanguageArray($l); 

// ---------------------------------------------------------

// set font
$pdf->SetFont('times', '', 10);

// add a page
$pdf->AddPage();



$students = students_taken($module_code);



$html = '

<table border="1">
<tr>
<th>Name</th>
<th>Student ID</th>';

for($i=1;$i<=num_courseworks($module_code);$i++)
  {
  	  $html.=' <th>CW'.$i.'</th>
		';
  }


$html.='<th>Exam</th>
<th>Overall</th>
</tr>';

foreach($students as $stu)
{



$html.='
<tr>
<td>'.strtoupper(get_name($stu,'student')).'</td>
<td>'.get_rollno($stu).'</td>';
for($i=1;$i<=num_courseworks($module_code);$i++)
  {
  	  $html.=' <th>'.cw_mark($stu,$module_code,$i).'</th>
		';
  }


$html.='
<td>'.exam_mark($stu,$module_code).'</td>
<td>'.round(total_marks($stu,$module_code)).'</td>
</tr>'

;



}

$html.='
</table>
   
  ';
  
 $no_students = count(students_taken($module_code));
  
  $first_class = no_student_above_mark($module_code,69.50,100);
 $second_upper = no_student_above_mark($module_code,59.50,69.49);
 $second_lower = no_student_above_mark($module_code,49.50,59.49);
  $third_class = no_student_above_mark($module_code,39.50,49.49);
   $fail = no_student_above_mark($module_code,0,39.49);
  
  
  $html.='
  <br/><br/><br/>
  
  <table border="1">
  <tr>
  <th width="70">Category</th>
  <th width="60">No.students</th>
  <th width="50">Percentage</th>
  </tr>
  
  <tr>
  <th width="70">FL(0%-39%)</th>
  <th width="60">'.$fail.'</th>
  <th width="50">'.round(($fail/$no_students*100)).'%</th>
  </tr>
  
    <tr>
  <th width="70">3rd(40%-49%)</th>
  <th width="60">'.$third_class.'</th>
  <th width="50">'.round(($third_class/$no_students*100)).'%</th>
  </tr>
  
    <tr>
  <th width="70">2.2(50-59%)</th>
  <th width="60">'.$second_lower.'</th>
  <th width="50">'.round(($second_lower/$no_students*100)).'%</th>
  </tr>
  
    <tr>
  <th width="70">2.1(60%-69%)</th>
  <th width="60">'.$second_upper.'</th>
  <th width="50">'.round(($second_upper/$no_students*100)).'%</th>
  </tr>
  
    <tr>
  <th width="70">1st(>70%)</th>
  <th width="60">'.$first_class.'</th>
  <th width="50">'.round(($first_class/$no_students*100)).'%</th>
  </tr>
  
      <tr>
  <th width="70">Total</th>
  <th width="60">'.$no_students.'</th>	
  <th width="50">'.round(($no_students/$no_students*100)).'%</th>
  </tr>
  
  
  
  </table>
  
  <br><br>
  Average :<b> '.round(average($module_code)).'</b><br>
  Maximum :<b> '.round(maximum($module_code)).'</b><br>
  Minimum :<b> '.round(minimum($module_code)).'</b><br>
 
  
  ';



$html.='
<br/><br/>	
<img src="graph.png" width="350" height="115">

';
  


$pdf->writeHtml($html);



// print a line using Cell()
//$pdf->Cell(0, 12, 'Example 001 - €אטילעש', 1, 1, 'C');

// ---------------------------------------------------------

//Close and output PDF document
$pdf->Output('Report_'.$module_code.'.pdf', 'I');


?>