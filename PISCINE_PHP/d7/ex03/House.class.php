<?php
abstract class House{
	abstract public function getHouseName();
	abstract public function getHouseMotto();
	abstract public function getHouseSeat();
	public function introduce(){
	print_r("House ");
	print_r($this->getHouseName());
	print_r(" of ");
	print_r($this->getHouseSeat());
	print_r(' : "');
	print_r($this->getHouseMotto());
	print_r('"' . PHP_EOL);
	}
}
?>