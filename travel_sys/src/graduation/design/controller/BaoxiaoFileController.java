package graduation.design.controller;

import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;
import java.util.List;
import java.util.ArrayList;
import javax.servlet.http.HttpSession;
import javax.servlet.http.HttpServletRequest;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import graduation.design.model.*;
import graduation.design.mapper.*;

import system.common.util.PageModel;

@Controller
@RequestMapping(value = "BaoxiaoFile")
public class BaoxiaoFileController {
	@Autowired
	private BaoxiaoFileMapper baoxiaoFileMapper;
	@Autowired
	private BaoxiaoStatusMapper baoxiaoStatusMapper;
	@Autowired
	private BaoxiaoTypeMapper baoxiaoTypeMapper;
	@Autowired
	private XibieMapper xibieMapper;
	@Autowired
	private UserMapper userMapper;

	@RequestMapping(value = "/initUtil.do")
	public String initUtil(HttpServletRequest request, Model model) {
		List<BaoxiaoStatus> listBaoxiaoStatus = baoxiaoStatusMapper.getObjectList(null, null);
		model.addAttribute("listBaoxiaoStatus", listBaoxiaoStatus);
		List<BaoxiaoType> listBaoxiaoType = baoxiaoTypeMapper.getObjectList(null, null);
		model.addAttribute("listBaoxiaoType", listBaoxiaoType);
		List<Xibie> listXibie = xibieMapper.getObjectList(null, null);
		model.addAttribute("listXibie", listXibie);
		List<User> listUser = userMapper.getObjectList(null, null);
		model.addAttribute("listUser", listUser);
		return "BaoxiaoFile/saveOrUpdate";
	}

	@RequestMapping(value = "/selectUtil.do")
	public String selectUtil(HttpServletRequest request, BaoxiaoFile util, Model model) {
		util = baoxiaoFileMapper.selectObject(util.getId());
		model.addAttribute("util", util);
		List<BaoxiaoStatus> listBaoxiaoStatus = baoxiaoStatusMapper.getObjectList(null, null);
		model.addAttribute("listBaoxiaoStatus", listBaoxiaoStatus);
		List<BaoxiaoType> listBaoxiaoType = baoxiaoTypeMapper.getObjectList(null, null);
		model.addAttribute("listBaoxiaoType", listBaoxiaoType);
		List<Xibie> listXibie = xibieMapper.getObjectList(null, null);
		model.addAttribute("listXibie", listXibie);
		List<User> listUser = userMapper.getObjectList(null, null);
		model.addAttribute("listUser", listUser);
		return "BaoxiaoFile/saveOrUpdate";
	}

	@SuppressWarnings({ "rawtypes", "unchecked" })
	@RequestMapping(value = "/getAllUtil.do")
	public String getAllUtil(HttpServletRequest request, Model model) {
		String field = request.getParameter("field");
		String fieldValue = request.getParameter("fieldValue");
		try {
			fieldValue = new String(fieldValue.getBytes("UTF-8"), "UTF-8");
		} catch (Exception e) {}
		String pageNo = request.getParameter("pageModel.currentPageNo");
		int currentPageNo = 1;
		try{
			currentPageNo = Integer.parseInt(pageNo);
		}catch(Exception e){
		}
		List<BaoxiaoFile> list = baoxiaoFileMapper.getObjectList(field, fieldValue);
		List<BaoxiaoFile> listBaoxiaoFile = new ArrayList<BaoxiaoFile>();
		HttpSession session = request.getSession();
		int user_id = (Integer) session.getAttribute("user_id");
		String user_type = (String) session.getAttribute("user_type");
		for (BaoxiaoFile temp : list) {
			if (user_id == temp.getUser().getId()) {
				listBaoxiaoFile.add(temp);
			}
		}
		if (!"admin".equals(user_type)) {
			//list = listBaoxiaoFile;
		}

		PageModel pageModel = new PageModel();
		pageModel = pageModel.getUtilByController(list, currentPageNo);
		model.addAttribute("pageModel", pageModel);
		model.addAttribute("fieldValue", fieldValue);
		model.addAttribute("field", field);
		return "BaoxiaoFile/find";
	}

	@RequestMapping(value = "/deleteUtil.do")
	public String deleteUtil(HttpServletRequest request, BaoxiaoFile util, Model model) {
		try{
			baoxiaoFileMapper.deleteObject(util.getId());
		}catch(Exception e){
		}
		return this.getAllUtil(request, model);
	}

	@RequestMapping(value = "/deleteManyUtil.do")
	public String deleteManyUtil(HttpServletRequest request, User util,
								 Model model) {
		String ids[] = request.getParameterValues("id");
		for (String id : ids) {
			util = new User();
			util.setId(Integer.parseInt(id));
			try{
				baoxiaoFileMapper.deleteObject(util.getId());
			}catch(Exception e){}
		}
		return this.getAllUtil(request, model);
	}

	@RequestMapping(value = "/saveOrUpdateObject.do")
	public String saveOrUpdateObject(HttpServletRequest request, BaoxiaoFile util, Model model) {
		List<BaoxiaoFile> list = baoxiaoFileMapper.getObjectList("s_0", util.getS_0());
		List<BaoxiaoStatus> listBaoxiaoStatus = baoxiaoStatusMapper.getObjectList(null, null);
		model.addAttribute("listBaoxiaoStatus", listBaoxiaoStatus);
		List<BaoxiaoType> listBaoxiaoType = baoxiaoTypeMapper.getObjectList(null, null);
		model.addAttribute("listBaoxiaoType", listBaoxiaoType);
		List<Xibie> listXibie = xibieMapper.getObjectList(null, null);
		model.addAttribute("listXibie", listXibie);
		List<User> listUser = userMapper.getObjectList(null, null);
		model.addAttribute("listUser", listUser);
		if (0 == util.getId()) {
			if (list.size() > 0) {
				model.addAttribute("util", util);
				model.addAttribute("errMsg", "该信息已存在!");
				return "BaoxiaoFile/saveOrUpdate";
			}
			baoxiaoFileMapper.insertObject(util);
		} else {
			if (list.size() > 1) {
				model.addAttribute("util", util);
				model.addAttribute("errMsg", "该信息已存在!");
				return "BaoxiaoFile/saveOrUpdate";
			}
			baoxiaoFileMapper.updateObject(util);
		}
		return this.getAllUtil(request, model);
	}

	@RequestMapping(value = "/upload.do")
	public String upload(HttpServletRequest request, BaoxiaoFile util, Model model) throws IOException{
		/*for (MultipartFile file : myfiles) {
			if (!file.isEmpty()) {
				String fileName = file.getOriginalFilename();
				String path = request.getSession().getServletContext()
						.getRealPath("upload")
						+ File.separator;
				String uploadName = new SimpleDateFormat("yyyyMMddHHmmss").format(new Date())
						+ fileName;
				File localFile = new File(path + uploadName);
				file.transferTo(localFile);
				util.setS_0(uploadName);
				util.setS_1(fileName);
				util.setS_2(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date()));
			}*/
				List<BaoxiaoFile> list = baoxiaoFileMapper.getObjectList("s_3", util.getS_3());
				List<BaoxiaoStatus> listBaoxiaoStatus = baoxiaoStatusMapper.getObjectList(null, null);
				model.addAttribute("listBaoxiaoStatus", listBaoxiaoStatus);
				List<BaoxiaoType> listBaoxiaoType = baoxiaoTypeMapper.getObjectList(null, null);
				model.addAttribute("listBaoxiaoType", listBaoxiaoType);
				List<Xibie> listXibie = xibieMapper.getObjectList(null, null);
				model.addAttribute("listXibie", listXibie);
				List<User> listUser = userMapper.getObjectList(null, null);
				model.addAttribute("listUser", listUser);
				if (0 == util.getId()) {
					if (list.size() > 0) {
						model.addAttribute("util", util);
						model.addAttribute("errMsg", "该信息已存在!");
						return "BaoxiaoFile/saveOrUpdate";
					}
					util.setS_0("None");
					util.setS_1("None");
					util.setS_2(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date()));
				} else {
					if (list.size() > 1) {
						model.addAttribute("util", util);
						model.addAttribute("errMsg", "该信息已存在!");
						return "BaoxiaoFile/saveOrUpdate";
					}
					BaoxiaoFile utilTmp = baoxiaoFileMapper.selectObject(util
							.getId());
					util.setS_0(utilTmp.getS_0());
					util.setS_1(utilTmp.getS_1());
					util.setS_2(utilTmp.getS_2());
				}
			if (0 == util.getId()) {
				baoxiaoFileMapper.insertObject(util);
			} else {
				baoxiaoFileMapper.updateObject(util);
			}

		return "BaoxiaoFile/ok";
	}
}
