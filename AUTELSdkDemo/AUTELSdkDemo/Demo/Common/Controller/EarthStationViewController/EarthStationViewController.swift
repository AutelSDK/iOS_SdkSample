//
//  EarthStationViewController.swift
//  AUTELSdkDemo
//
//  Created by zhiganglet on 2020/5/7.
//  Copyright © 2020 AUTEL. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation
import AUTELSDK



/// Map controller, which displays the flight information of the aircraft on the map
class EarthStationViewController: UIViewController, UIGestureRecognizerDelegate {
    var vm = EarthStationViewModel()
    
    var locationManager:CLLocationManager = CLLocationManager()
    var mapView = MKMapView.init()

    override func viewDidLoad() {
        super.viewDidLoad()

        initLocationManager()
        setupSubviews()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        MainControllerConnection.shared.addProtocol(self)
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        MainControllerConnection.shared.removeProtocol()
        
    }
    
    override var supportedInterfaceOrientations: UIInterfaceOrientationMask{
        return UIInterfaceOrientationMask.landscape
    }
    
    func setupSubviews() {
//        view.backgroundColor = UIColor.white
        //Configure the map
        view.addSubview(mapView)
        view.sendSubviewToBack(mapView)
        mapView.delegate = vm
        mapView.snp.makeConstraints { (maker) in
            maker.edges.equalToSuperview()
        }
        self.view.layoutIfNeeded()
    }
    
    
    /// Turn on location services
    func initLocationManager() {
        locationManager.delegate = self;
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        let authStatus = CLLocationManager.authorizationStatus()
        if authStatus != .authorizedWhenInUse && authStatus != .authorizedAlways {
            locationManager.requestWhenInUseAuthorization()
        }
        locationManager.startUpdatingLocation()
        locationManager.startUpdatingHeading()
        
        mapView.userLocation.title = nil
        mapView.showsUserLocation = true
        mapView.isUserInteractionEnabled = true
        mapView.showsCompass = true
        // scale
        mapView.showsScale = true
        
    }
}

extension EarthStationViewController {
    /// Locate the location of the mobile device
    func locaitToDevice() {
        guard let es_deviceCoordinate = vm.es_deviceCoordinate else {
            return
        }
        if CLLocationCoordinate2DIsValid(es_deviceCoordinate) {
            weak var weakself = self
            DispatchQueue.main.async {
                let coordinateRegin = MKCoordinateRegion.init(center: (es_deviceCoordinate),  span: MKCoordinateSpan.init(latitudeDelta: 0.001, longitudeDelta: 0.001))
                weakself?.mapView.setRegion(coordinateRegin, animated: true)
            }
        }
    }
}


//MARK: CLLocationManagerDelegate

extension EarthStationViewController: CLLocationManagerDelegate {

    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        switch status {
        case .authorizedAlways, .authorizedWhenInUse:
            locationManager.startUpdatingLocation()
            mapView.showsUserLocation = true
        default:
            locationManager.stopUpdatingLocation()
            mapView.showsUserLocation = false
        }
    }
        
    func locationManager(_ manager: CLLocationManager, didUpdateHeading newHeading: CLHeading) {
        if newHeading.headingAccuracy < 0 {
            return
        }
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        
        let deviceCoordinate: CLLocationCoordinate2D? = vm.es_deviceCoordinate
        
        if locations.last != nil {
            vm.es_deviceCoordinate = (locations.last)!.coordinate
            vm.es_deviceCoordinateNoCalibrared = (locations.last)!.coordinate
            if (vm.isMapCalibrared) {
                vm.es_deviceCoordinate = MapCorrect.wgs2gcj(with:vm.es_deviceCoordinateNoCalibrared!)
            }
        }
        
        //Locate the location of the mobile device for the first time
        if deviceCoordinate == nil && vm.es_deviceCoordinate != nil {
            locaitToDevice()
        }
        
    }
    
}
