package main.controller;

import main.entity.*;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.*;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

import static main.utils.Utils.*;

@Controller
public class PeopleController {
    private User user;

    @GetMapping("/people")
    public String getPeoplePage(Model model) {
        model.addAttribute("title", "People");

        String url = "http://localhost:8080/people/all";
        List<People> people = processGetRequest(url, List.class);
        model.addAttribute("people", people);

        return "people/people";
    }

    @GetMapping("/people/add")
    public String getAddPage(Model model) {
        model.addAttribute("title", "Add people");

        String wardsURL = "http://localhost:8080/wards/all";
        String diagnosisURL = "http://localhost:8080/diagnosis/all";
        List<Wards> wardsList = processGetRequest(wardsURL, List.class);
        List<Diagnosis> diagnosisList = processGetRequest(diagnosisURL, List.class);
        model.addAttribute("wards", wardsList);
        model.addAttribute("diagnosis", diagnosisList);

        return "people/addPeople";
    }

    @GetMapping("/people/edit/{id}")
    public String getEditPage(@PathVariable long id, Model model) {
        model.addAttribute("title", "Edit people");

        String peopleURL = "http://localhost:8080/people/" + id;
        String wardsURL = "http://localhost:8080/wards/all";
        String diagnosisURL = "http://localhost:8080/diagnosis/all";
        People people = processGetRequest(peopleURL, People.class);
        List<Wards> wards = processGetRequest(wardsURL, List.class);
        List<Diagnosis> diagnosis = processGetRequest(diagnosisURL, List.class);
        model.addAttribute("people", people);
        model.addAttribute("wards", wards);
        model.addAttribute("diagnosis", diagnosis);

        return "people/editPeople";
    }

    @PostMapping("/people/add")
    public String addPeople(@RequestParam String firstName, @RequestParam String lastName, @RequestParam String patherName,
                            @RequestParam long wardId, @RequestParam long diagnoseId) {
        String url = "http://localhost:8080/people/add";
        String json = "{\n" +
                "\"firstName\":" + "\"" + firstName + "\",\n" +
                "\"lastName\":" + "\"" + lastName + "\",\n" +
                "\"patherName\":" + "\"" + patherName + "\",\n" +
                "\"ward\":{" + "\"id\":" + wardId + "},\n" +
                "\"diagnose\":{" + "\"id\":" + diagnoseId + "}\n" + "}";

        processPostRequest(url, user.getToken(), json, HttpMethod.POST, MediaType.APPLICATION_JSON);
        return "redirect:/people";
    }

    @PostMapping("/people/edit/{id}")
    public String editPeople(@PathVariable("id") long id, @RequestParam String firstName, @RequestParam String lastName,
                             @RequestParam String patherName, @RequestParam long wardId,
                             @RequestParam long diagnoseId) {
        String fullNameURL = "http://localhost:8080/people/update/fullName/" + id +
                "?firstName=" + firstName +
                "&lastName=" + lastName +
                "&patherName=" + patherName;
        String wardURL = "http://localhost:8080/people/update/ward/" + id + "?wardId=" + wardId;
        String diagnoseURL = "http://localhost:8080/people/update/diagnose/" + id + "?diagnoseId=" + diagnoseId;

        processPostRequest(fullNameURL, user.getToken(), null, HttpMethod.PUT, null);
        processPostRequest(wardURL, user.getToken(), null, HttpMethod.PUT, null);
        processPostRequest(diagnoseURL, user.getToken(), null, HttpMethod.PUT, null);
        return "redirect:/people";
    }

    @PostMapping("/people/delete/{id}")
    public String deletePeople(@PathVariable("id") long id) {
        String url = "http://localhost:8080/people/delete/" + id;

        processPostRequest(url, user.getToken(), null, HttpMethod.DELETE, null);
        return "redirect:/people";
    }

    @Autowired
    public void setUser(User user) {
        this.user = user;
    }
}
