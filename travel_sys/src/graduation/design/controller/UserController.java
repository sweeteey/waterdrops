package graduation.design.controller;

import graduation.design.mapper.UserMapper;
import graduation.design.model.User;

import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

import org.apache.tools.util.SysUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import system.common.util.PageModel;

@Controller
@RequestMapping(value = "User")
public class UserController {
	@Autowired
	private UserMapper userMapper;

	@RequestMapping(value = "/login.do")
	public String login(HttpServletRequest request, User util, Model model) {

		HttpSession session = request.getSession();
		String code = (String) session.getAttribute("code");
		String userCode = request.getParameter("code");

		System.out.println("111");
		if (!code.equals(userCode)) {
			model.addAttribute("errMsg", "验证码错误");
			return "../login";
		}
		System.out.println("222");
		User user = userMapper.getObjectByName(util);
		/*User user = new User();
		user.setS_1(util.getS_1());*/

		System.out.println("333");
		if (null == user) {
			model.addAttribute("errMsg", "登录失败");
			return "../login";
		}
		System.out.println("444");
		boolean flag = user.getS_1().equals(util.getS_1());
		if (!flag) {
			model.addAttribute("errMsg", "登录失败");
			return "../login";
		}
		System.out.println("555");
		session.setAttribute("user_id", user.getId());
		session.setAttribute("user_type", user.getS_11());
		session.setAttribute("type1", "admin");
		session.setAttribute("type2", "admin");
		session.setAttribute("name", user.getS_2());
		session.setAttribute("username", user.getS_0());
		System.out.println("333");
		return "../index";
	}

	@RequestMapping(value = "/updatepwd.do")
	public String updatepwd(HttpServletRequest request, User util, Model model) {

		HttpSession session = request.getSession();
		int user_id = (Integer) session.getAttribute("user_id");
		User userTmp = userMapper.selectObject(user_id);

		String oldPwd = util.getS_3();
		String newPwd = util.getS_4();
		String rePwd = util.getS_5();
		if (null == oldPwd || "".equals(oldPwd) || null == newPwd
				|| "".equals(newPwd) || null == rePwd || "".equals(rePwd)) {
			model.addAttribute("errMsg", "密码信息不能为空");
			model.addAttribute("util", userTmp);
			return "User/updatepwd";
		}

		if (!newPwd.equals(rePwd)) {
			model.addAttribute("errMsg", "确认密码不一致");
			model.addAttribute("util", userTmp);
			return "User/updatepwd";
		}

		if (newPwd.equals(oldPwd)) {
			model.addAttribute("errMsg", "旧密码不能与新密码一致");
			model.addAttribute("util", userTmp);
			return "User/updatepwd";
		}

		if (!oldPwd.equals(userTmp.getS_1())) {
			model.addAttribute("errMsg", "旧密码错误");
			model.addAttribute("util", userTmp);
			return "User/updatepwd";
		}
		userTmp.setS_1(newPwd);
		userMapper.updateObject(userTmp);
		return "User/uppwdok";
	}

	@RequestMapping(value = "/updateinfo.do")
	public String updateinfo(HttpServletRequest request, User util, Model model) {
		userMapper.updateObject(util);
		model.addAttribute("util", util);
		model.addAttribute("errMsg", "个人信息修改成功");
		return "User/updateinfo";
	}

	@RequestMapping(value = "/beforepass.do")
	public String beforepass(HttpServletRequest request, User util, Model model) {
		HttpSession session = request.getSession();
		int user_id = (Integer) session.getAttribute("user_id");
		util = userMapper.selectObject(user_id);
		model.addAttribute("util", util);
		return "User/updatepwd";
	}

	@RequestMapping(value = "/beforeinfo.do")
	public String beforeinfo(HttpServletRequest request, User util, Model model) {
		HttpSession session = request.getSession();
		int user_id = (Integer) session.getAttribute("user_id");
		util = userMapper.selectObject(user_id);
		model.addAttribute("util", util);
		return "User/updateinfo";
	}

	@RequestMapping(value = "/register.do")
	public String register(HttpServletRequest request, User util, Model model) {
		HttpSession session = request.getSession();
		User user = userMapper.getObjectByName(util);
		if (null != user) {
			model.addAttribute("errMsg", "该用户名已经存在");
			return "../register";
		}
		userMapper.insertObject(util);
		model.addAttribute("registerMsg", "恭喜您，注册成功！");
		return "../login";
	}

	@RequestMapping(value = "/initUtil.do")
	public String initUtil(HttpServletRequest request, Model model) {
		return "User/saveOrUpdate";
	}

	@RequestMapping(value = "/selectUtil.do")
	public String selectUtil(HttpServletRequest request, User util, Model model) {
		util = userMapper.selectObject(util.getId());
		model.addAttribute("util", util);
		return "User/saveOrUpdate";
	}

	@SuppressWarnings({ "rawtypes", "unchecked" })
	@RequestMapping(value = "/getAllUtil.do")
	public String getAllUtil(HttpServletRequest request, User util, Model model) {
		String field = request.getParameter("field");
		String fieldValue = request.getParameter("fieldValue");
		String pageNo = request.getParameter("pageModel.currentPageNo");
		int currentPageNo = 1;
		try {
			fieldValue = new String(fieldValue.getBytes("UTF-8"), "UTF-8");
			currentPageNo = Integer.parseInt(pageNo);
		} catch (Exception e) {
		}
		List<User> list = userMapper.getObjectList(field, fieldValue);
		PageModel pageModel = new PageModel();
		pageModel = pageModel.getUtilByController(list, currentPageNo);
		model.addAttribute("pageModel", pageModel);
		model.addAttribute("fieldValue", fieldValue);
		model.addAttribute("field", field);
		return "User/find";
	}

	@RequestMapping(value = "/deleteManyUtil.do")
	public String deleteManyUtil(HttpServletRequest request, User util,
								 Model model) {
		String ids[] = request.getParameterValues("id");
		for (String id : ids) {
			util = new User();
			util.setId(Integer.parseInt(id));
			try {
				userMapper.deleteObject(util.getId());
			} catch (Exception e) {
			}
		}
		return this.getAllUtil(request, util, model);
	}

	@RequestMapping(value = "/deleteUtil.do")
	public String deleteUtil(HttpServletRequest request, User util, Model model) {
		try {
			userMapper.deleteObject(util.getId());
		} catch (Exception e) {
		}
		return this.getAllUtil(request, util, model);
	}

	@RequestMapping(value = "/saveOrUpdateObject.do")
	public String saveOrUpdateObject(HttpServletRequest request, User util,
									 Model model) {
		List<User> list = userMapper.getObjectList("s_0", util.getS_0());
		if (0 == util.getId()) {
			if (list.size() > 0) {
				model.addAttribute("util", util);
				model.addAttribute("errMsg", "该信息已存在!");
				return "User/saveOrUpdate";
			}
			userMapper.insertObject(util);
		} else {
			if (list.size() > 1) {
				model.addAttribute("util", util);
				model.addAttribute("errMsg", "该信息已存在!");
				return "User/saveOrUpdate";
			}
			userMapper.updateObject(util);
		}
		return this.getAllUtil(request, util, model);
	}

	@RequestMapping(value = "/upload.do")
	public String upload(@RequestParam MultipartFile[] myfiles,
						 HttpServletRequest request, User util, Model model)
			throws IOException {
		for (MultipartFile file : myfiles) {
			if (!file.isEmpty()) {
				String fileName = file.getOriginalFilename();
				String path = request.getSession().getServletContext()
						.getRealPath("image")
						+ File.separator;
				String uploadName = new SimpleDateFormat("yyyyMMddHHmmss")
						.format(new Date()) + fileName;
				File localFile = new File(path + uploadName);
				file.transferTo(localFile);
				util.setS_0(uploadName);
				util.setS_1(fileName);
				util.setS_2(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss")
						.format(new Date()));
			}

			if (0 == util.getId()) {
				userMapper.insertObject(util);
			} else {
				userMapper.updateObject(util);
			}
			return this.getAllUtil(request, util, model);
		}

		return this.getAllUtil(request, util, model);
	}
}
